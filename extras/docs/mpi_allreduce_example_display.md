# MPI Allreduce Example — Source Code (Extras)

This is the reference MPI program used in the **Day 5 Optional Mini-Lab**.

```c
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static double serial_sum(const double *a, size_t n){
    double s = 0.0;
    for(size_t i=0;i<n;i++) s += a[i];
    return s;
}

int main(int argc, char **argv){
    MPI_Init(&argc, &argv);
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    size_t N = (argc>1)? strtoull(argv[1], NULL, 10) : (size_t)1000000;
    size_t localN = (N + size - 1)/size; // block distribution
    size_t start = (size_t)rank * localN;
    size_t end   = start + localN;
    if(end > N) end = N;
    localN = (end>start)? (end-start):0;

    double *a = (double*)malloc(localN*sizeof(double));
    if(!a){ if(rank==0) fprintf(stderr,"alloc failed\n"); MPI_Abort(MPI_COMM_WORLD, 1); }

    // deterministic init for reproducibility
    for(size_t i=0;i<localN;i++) a[i] = 1.0 + ((start+i)%7);

    // local reduction
    double local = 0.0;
    for(size_t i=0;i<localN;i++) local += a[i];

    // collective allreduce
    double global = 0.0;
    double t0 = MPI_Wtime();
    MPI_Allreduce(&local, &global, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
    double t1 = MPI_Wtime();

    if(rank == 0){
        printf("N=%zu ranks=%d sum=%.1f allreduce_time=%.6f s\n", N, size, global, t1-t0);
    }

    // Optional: do serial baseline only on rank 0 for small N
    if(rank == 0 && N <= (size_t)5000000){
        double *b = (double*)malloc(N*sizeof(double));
        if(b){
            for(size_t i=0;i<N;i++) b[i] = 1.0 + (i%7);
            double s = serial_sum(b, N);
            printf("Serial baseline sum=%.1f\n", s);
            free(b);
        }
    }

    free(a);
    MPI_Finalize();
    return 0;
}
```