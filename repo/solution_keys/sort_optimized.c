#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "common.h"

static int cmp_int(const void* a, const void* b){
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    return (ia>ib) - (ia<ib);
}

int main(int argc, char** argv){
    int n = (argc>1)? atoi(argv[1]) : 200000;
    unsigned seed = (argc>2)? (unsigned)strtoul(argv[2], NULL, 10) : 42U;
    srand(seed);

    int *arr = (int*)aligned_malloc((size_t)n*sizeof(int), 64);
    for(int i=0;i<n;i++) arr[i] = rand();

    double t0 = wall_time_s();
    qsort(arr, n, sizeof(int), cmp_int);
    double t1 = wall_time_s();

    // verify non-decreasing
    int ok = 1;
    for(int i=1;i<n;i++){ if(arr[i-1] > arr[i]){ ok=0; break; } }

    printf("n=%d time=%.6f s sorted=%s first=%d last=%d\n", n, (t1-t0), ok?"yes":"no", arr[0], arr[n-1]);
    aligned_free(arr);
    return ok?0:1;
}
