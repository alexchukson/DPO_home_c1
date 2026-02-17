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

void dec_to_bin(int n){
  if (n >= 2)
    dec_to_bin(n / 2);
  printf("%d", n % 2);
}


void main(){
    int n = 0;
    scanf("%d", &n);
    dec_to_bin(n);
    printf("\n");
    exit(0);
}