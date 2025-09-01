#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#ifdef USE_CBLAS
  #include <cblas.h>
#endif

// BLAS matmul reference (dgemm). Build with: make matmul_blas CBLAS=1
// Args: N
int main(int argc, char** argv){
#ifndef USE_CBLAS
    fprintf(stderr, "matmul_blas built without CBLAS. Rebuild with CBLAS=1 and BLAS_LIBS set.\n");
    return 1;
#else
    int N = (argc>1)? atoi(argv[1]) : 512;
    size_t bytes = (size_t)N*(size_t)N*sizeof(double);
    double *A = (double*)aligned_malloc(bytes, 64);
    double *B = (double*)aligned_malloc(bytes, 64);
    double *C = (double*)aligned_malloc(bytes, 64);
    for (size_t i=0;i<(size_t)N*(size_t)N;i++){ A[i]=1.0; B[i]=1.0; C[i]=0.0; }

    double t0 = wall_time_s();
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                N, N, N, 1.0, A, N, B, N, 0.0, C, N);
    double t1 = wall_time_s();

    double flops = 2.0 * (double)N * (double)N * (double)N;
    double gflops = (flops / (t1 - t0)) * 1e-9;

    printf("BLAS dgemm: N=%d time=%.6f s perf=%.2f GFLOP/s C[0]=%.1f\n",
           N, (t1-t0), gflops, C[0]);

    aligned_free(A); aligned_free(B); aligned_free(C);
    return 0;
#endif
}
