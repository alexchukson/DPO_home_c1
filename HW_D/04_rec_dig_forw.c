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
        digBack(num / 10);
    }else{
        // printf("%d ", num % 10);
        return 0;
    }
}

int digForw(int num) {
    if (num > 0){
        digForw(num / 10);
        printf("%d ", num % 10);
    }else{
        // printf("%d ", num % 10);
        return 0;
    }
}
void main(){
    int n = 0;
    scanf("%d", &n);
    if (n == 0) {
        printf("0\n");
        exit(0);
    }
    digForw(n);
    printf("\n");
    exit(0);
}