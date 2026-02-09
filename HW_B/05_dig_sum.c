#include <stdio.h>

void main(){
    int n = 0, digSum = 0;
    scanf("%d ", &n);
    while ( n!= 0){
        digSum += n % 10;
        n /= 10;
    }
    printf("%d \n", digSum);
    exit(0);
}