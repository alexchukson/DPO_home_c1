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

int sumRec(int num) {
    if (num > 0)
        return num + sumRec(num - 1);
    else
        return 0;
}

int digBack(int num) {
    if (num > 0){
        printf("%d ", num % 10);
        return num % 10 + sumRec(num / 10);
    }else
        return 0;
}

void main(){
    int n = 0;
    scanf("%d", &n);
    printf("%d \n", sumRec(n));
    exit(0);
}