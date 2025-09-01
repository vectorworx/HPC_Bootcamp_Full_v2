#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

static double dot_naive(const double *a, const double *b, size_t n){
    double s = 0.0;
    for(size_t i=0;i<n;i++) s += a[i]*b[i];
    return s;
}

static double dot_kahan(const double *a, const double *b, size_t n){
    double sum = 0.0, c = 0.0;
    for(size_t i=0;i<n;i++){
        double y = a[i]*b[i] - c;
        double t = sum + y;
        c = (t - sum) - y;
        sum = t;
    }
    return sum;
}

int main(int argc,char**argv){
    size_t n = (argc>1)?strtoull(argv[1],NULL,10):1000000;
    unsigned seed = (argc>2)?(unsigned)strtoul(argv[2],NULL,10):(unsigned)42;
    srand(seed);

    double *a = (double*)malloc(n*sizeof(double));
    double *b = (double*)malloc(n*sizeof(double));
    if(!a || !b){ fprintf(stderr,"alloc failed\n"); return 1; }

    for(size_t i=0;i<n;i++){
        a[i] = ((rand()%1000) - 500) / 1000.0; // [-0.5, 0.5]
        b[i] = ((rand()%1000) - 500) / 1000.0;
    }

    clock_t t0 = clock();
    double s1 = dot_naive(a,b,n);
    clock_t t1 = clock();
    double s2 = dot_kahan(a,b,n);
    clock_t t2 = clock();

    double dt_naive = (double)(t1 - t0) / CLOCKS_PER_SEC;
    double dt_kahan = (double)(t2 - t1) / CLOCKS_PER_SEC;

    printf("naive=%.15f (%.6fs)  kahan=%.15f (%.6fs)  diff=%.3e\n",
           s1, dt_naive, s2, dt_kahan, fabs(s1-s2));

    free(a); free(b);
    return 0;
}
