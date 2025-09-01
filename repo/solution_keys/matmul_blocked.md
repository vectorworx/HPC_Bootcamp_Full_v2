# matmul_blocked.c — Solution Keys Wrapper

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <immintrin.h>
#include "common.h"

// Simple cache-blocked/tiled matmul: C = A * B (row-major), doubles
// A,B initialized to 1.0 so C[i,j] == N
// Args: N [T=32]
int main(int argc, char** argv){
    int N = (argc>1)? atoi(argv[1]) : 512;
    int T = (argc>2)? atoi(argv[2]) : 32;
    size_t bytes = (size_t)N*(size_t)N*sizeof(double);

    double *A = (double*)aligned_malloc(bytes, 64);
    double *B = (double*)aligned_malloc(bytes, 64);
    double *C = (double*)aligned_malloc(bytes, 64);

    for (size_t i=0;i<(size_t)N*(size_t)N;i++){ A[i]=1.0; B[i]=1.0; C[i]=0.0; }

    double t0 = wall_time_s();
    for (int ii=0; ii<N; ii+=T){
        for (int jj=0; jj<N; jj+=T){
            for (int kk=0; kk<N; kk+=T){
                int iimax = (ii+T<N)? (ii+T) : N;
                int jjmax = (jj+T<N)? (jj+T) : N;
                int kkmax = (kk+T<N)? (kk+T) : N;
                for (int i=ii; i<iimax; ++i){
                    for (int k=kk; k<kkmax; ++k){
                        double aik = A[(size_t)i*N + k];
                        double * restrict Bj = &B[(size_t)k*N + jj];
                        double * restrict Cij = &C[(size_t)i*N + jj];
                        for (int j=jj; j<jjmax; ++j){
                            Cij[j-jj] += aik * Bj[j-jj];
                        }
                    }
                }
            }
        }
    }
    double t1 = wall_time_s();

    // FLOPs ~ 2*N^3
    double flops = 2.0 * (double)N * (double)N * (double)N;
    double gflops = (flops / (t1 - t0)) * 1e-9;

    printf("N=%d T=%d time=%.6f s  perf=%.2f GFLOP/s  C[0]=%.1f\n",
           N, T, (t1-t0), gflops, C[0]);

    aligned_free(A); aligned_free(B); aligned_free(C);
    return 0;
}

```
