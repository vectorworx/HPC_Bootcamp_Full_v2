#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

static inline double wall_time_s(void){
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

static inline void* aligned_malloc(size_t nbytes, size_t align){
    void *p = NULL;
#if defined(_MSC_VER)
    p = _aligned_malloc(nbytes, align);
    if(!p){ fprintf(stderr,"_aligned_malloc failed\n"); exit(1); }
#else
    if(posix_memalign(&p, align, nbytes) != 0 || !p){
        fprintf(stderr,"posix_memalign failed\n");
        exit(1);
    }
#endif
    return p;
}

static inline void aligned_free(void* p){
#if defined(_MSC_VER)
    _aligned_free(p);
#else
    free(p);
#endif
}
