# N-Queens (Backtracking) — Source Code

```c
#include <stdio.h>
#include <stdlib.h>

int N,solutions=0;int*board;

int safe(int r,int c){
    for(int i=0;i<r;i++)
        if(board[i]==c||abs(board[i]-c)==abs(i-r)) return 0;
    return 1;
}

void solve(int r){
    if(r==N){solutions++;return;}
    for(int c=0;c<N;c++)
        if(safe(r,c)){board[r]=c;solve(r+1);}
}

int main(int argc,char*argv[]){
    N=(argc>1)?atoi(argv[1]):12;
    board=malloc(N*sizeof(int));
    solve(0);
    printf("Solutions=%d\n",solutions);
    free(board);
    return 0;
}
```