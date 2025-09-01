#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "common.h"

// N-Queens with OpenMP tasks. Args: N [cutoff=4]
static int N;
static long long solutions = 0;

static int safe(const int *board, int row, int col){
    for (int i=0;i<row;i++){
        if (board[i]==col || abs(board[i]-col)==abs(i-row)) return 0;
    }
    return 1;
}

static void solve_recursive(int *board, int row, int cutoff){
    if (row == N) {
#pragma omp atomic
        solutions++;
        return;
    }
    for (int col=0; col<N; ++col){
        if (safe(board, row, col)){
            board[row] = col;
            if (row < cutoff){
#pragma omp task firstprivate(board, row) shared(cutoff)
                {
                    int *b2 = (int*)malloc(N*sizeof(int));
                    for(int i=0;i<=row;i++) b2[i]=board[i];
                    solve_recursive(b2, row+1, cutoff);
                    free(b2);
                }
            } else {
                solve_recursive(board, row+1, cutoff);
            }
        }
    }
}

int main(int argc, char** argv){
    N = (argc>1)? atoi(argv[1]) : 12;
    int cutoff = (argc>2)? atoi(argv[2]) : 4;

    int *board = (int*)calloc(N, sizeof(int));
    double t0 = wall_time_s();
#pragma omp parallel
    {
#pragma omp single nowait
        solve_recursive(board, 0, cutoff);
    }
    double t1 = wall_time_s();

    printf("N=%d cutoff=%d solutions=%lld time=%.6f s\n", N, cutoff, solutions, (t1-t0));
    free(board);
    return 0;
}
