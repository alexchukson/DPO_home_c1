#include <stdio.h>

void main(){
    int n = 0;
    // printf("Enter 3 int numbers: \n");
    scanf("%d", &n);
    for ( int i = 1; i <= n; i++)
        printf("%d %d %d \n", i, i*i, i*i*i);
    exit(0);
}