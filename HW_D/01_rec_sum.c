#include <stdio.h>

int printN(int n){
    printf("%d ", n);
    n --;
    if (n == 0) return 0;
    n = printN(n);
}

void recursionFor(int i, int n) {
    printf("%d ", i);
    if(i==n) return;
    recursionFor(i+1, n);
}

void main(){
    int n = 0;
    scanf("%d", &n);
    recursionFor(1, n);
    printf("\n");
    exit(0);
}