#include <stdio.h>

void main(){
    int n1 = 0, n2 = 0;
    scanf("%d %d ", &n1, &n2);
    for ( int i = n1; i <= n2; i++)
        printf("%d ", i*i);
    printf("\n");
    exit(0);
}