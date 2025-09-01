#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "common.h"

// OpenMP matmul: C = A * B (row-major), doubles
// A,B initialized to 1.0 so C[i,j] == N
// Args: N
int main(int argc, char** argv){
    int N = (argc>1)? atoi(argv[1]) : 1024;
    size_t bytes = (size_t)N*(size_t)N*sizeof(double);

    double *A = (double*)aligned_malloc(bytes, 64);
    double *B = (double*)aligned_malloc(bytes, 64);
    double *C = (double*)aligned_malloc(bytes, 64);

    for (size_t i=0;i<(size_t)N*(size_t)N;i++){ A[i]=1.0; B[i]=1.0; C[i]=0.0; }

    double t0 = wall_time_s();
#pragma omp parallel for schedule(static)
    for (int i=0; i<N; ++i){
        for (int j=0; j<N; ++j){
            double sum = 0.0;
            for (int k=0; k<N; ++k){
                sum += A[(size_t)i*N + k] * B[(size_t)k*N + j];
            }
            C[(size_t)i*N + j] = sum;
        }
    }
    double t1 = wall_time_s();

    // FLOPs ~ 2*N^3
    double flops = 2.0 * (double)N * (double)N * (double)N;
    double gflops = (flops / (t1 - t0)) * 1e-9;

    int threads = 1;
#pragma omp parallel
    { #pragma omp master
      threads = omp_get_num_threads(); }

    printf("N=%d threads=%d time=%.6f s perf=%.2f GFLOP/s C[0]=%.1f\n",
           N, threads, (t1-t0), gflops, C[0]);

    aligned_free(A); aligned_free(B); aligned_free(C);
    return 0;
}
