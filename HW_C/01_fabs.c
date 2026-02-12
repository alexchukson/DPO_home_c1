#include <stdio.h>

int my_abs(int n){
    return n >= 0 ?  n: -n;
}

void main(){
    int n = 0;
    scanf("%d ", &n);
    printf("%d \n", my_abs(n));
    exit(0);
}