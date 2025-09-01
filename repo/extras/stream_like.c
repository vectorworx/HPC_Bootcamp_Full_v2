#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include <sys/time.h>

/*
 * STREAM-like Triad:
 *   a[i] = b[i] + s * c[i]
 *
 * Reports bandwidth = bytes_moved / time for the main kernel.
 * Bytes moved per element (triad) ≈ sizeof(double) * (2 loads + 1 store) = 24 bytes
 * (Ignoring write-allocate effects; your platform may add RFO traffic.)
 *
 * Usage: ./stream_like [N] [reps] [scalar]
 *   N:    number of elements (default 100_000_000)
 *   reps: number of timed repetitions (default 10)
 *   s:    scalar multiplier (default 3.0)
 *
 * Build:
 *   gcc -O3 -march=native -fopenmp stream_like.c -o stream_like
 *
 * Notes:
 * - Pin threads with OMP_* env vars for stability, e.g.:
 *     export OMP_PROC_BIND=close; export OMP_PLACES=cores; export OMP_NUM_THREADS=$(nproc)
 */

static inline double now_sec(void){
#if defined(CLOCK_MONOTONIC)
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec + ts.tv_nsec*1e-9;
#else
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + tv.tv_usec*1e-6;
#endif
}

int main(int argc, char** argv){
    size_t N = (argc>1)? strtoull(argv[1], NULL, 10) : (size_t)100000000ULL;
    int reps   = (argc>2)? atoi(argv[2]) : 10;
    double s   = (argc>3)? atof(argv[3]) : 3.0;

    size_t bytes = N * sizeof(double);
    double *a = NULL, *b = NULL, *c = NULL;

    if (posix_memalign((void**)&a, 64, bytes) ||
        posix_memalign((void**)&b, 64, bytes) ||
        posix_memalign((void**)&c, 64, bytes)) {
        fprintf(stderr, "posix_memalign failed\n");
        return 1;
    }

    // Initialize
    for (size_t i=0;i<N;i++){ b[i]=1.0; c[i]=2.0; a[i]=0.0; }

    // Warmup
    for (int r=0;r<2;r++){
#pragma omp parallel for schedule(static)
        for (size_t i=0;i<N;i++){
            a[i] = b[i] + s * c[i];
        }
    }

    // Timed reps
    double best = 1e30, sum = 0.0;
    for (int r=0;r<reps;r++){
        double t0 = now_sec();
#pragma omp parallel for schedule(static) reduction(+:sum)
        for (size_t i=0;i<N;i++){
            double ai = b[i] + s * c[i];
            a[i] = ai;
            sum += ai; // tiny reduction to keep compiler honest
        }
        double t1 = now_sec();
        double dt = t1 - t0;
        if (dt < best) best = dt;
    }

    // Approx bytes moved (ignore RFO): 24 * N per rep
    double bytes_moved = 24.0 * (double)N;
    double gbps = (bytes_moved / best) * 1e-9;

    // Prevent dead-code elimination
    volatile double guard = a[0] + sum*1e-30;
    (void)guard;

    int threads = 1;
#ifdef _OPENMP
    #pragma omp parallel
    { #pragma omp master
      threads = omp_get_num_threads(); }
#endif

    printf("STREAM-like Triad: N=%zu reps=%d threads=%d\n", N, reps, threads);
    printf("Best time: %.6f s  Approx BW: %.2f GB/s\n", best, gbps);
    printf("Note: BW ignores RFO/write-allocate traffic; real DRAM BW may be higher.\n");

    free(a); free(b); free(c);
    return 0;
}
