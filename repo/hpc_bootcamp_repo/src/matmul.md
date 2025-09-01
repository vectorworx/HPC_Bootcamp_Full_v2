# Matrix Multiplication (Naive) — Source Code

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char*argv[]){
    int N=(argc>1)?atoi(argv[1]):256;
    double *A=malloc(N*N*sizeof(double));
    double *B=malloc(N*N*sizeof(double));
    double *C=malloc(N*N*sizeof(double));
    for(int i=0;i<N*N;i++){A[i]=1.0;B[i]=1.0;C[i]=0.0;}
    for(int i=0;i<N;i++)
      for(int j=0;j<N;j++)
        for(int k=0;k<N;k++)
          C[i*N+j]+=A[i*N+k]*B[k*N+j];
    printf("C[0]=%f\n",C[0]);
    free(A);free(B);free(C);
    return 0;
}
```