#include <stdio.h>

void main(){
    int n;
    scanf("%d ", &n);
    if ( n > 99 && n < 1000 ) printf("YES\n");
    else printf("NO\n");
    exit(0);
}