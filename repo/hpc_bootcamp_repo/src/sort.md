# Naive Bubble Sort — Source Code

```c
#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *a,int n){
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(a[j]>a[j+1]){
                int t=a[j];a[j]=a[j+1];a[j+1]=t;
            }
}

int main(int argc,char*argv[]){
    int n=(argc>1)?atoi(argv[1]):10000;
    int *arr=malloc(n*sizeof(int));
    for(int i=0;i<n;i++) arr[i]=rand()%1000;
    bubble_sort(arr,n);
    printf("arr[0]=%d arr[n-1]=%d\n",arr[0],arr[n-1]);
    free(arr);
    return 0;
}
```