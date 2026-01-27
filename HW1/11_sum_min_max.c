#include <stdio.h>
int max(int a, int b){
    return a > b ? a : b;
}

int min(int a, int b){
    return a < b ? a : b;
}

void main(){
    int a = 0, b = 0, c = 0, d = 0, e = 0;
    // printf("Enter 3 int numbers: \n");
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
    int M = max(a, max(b, max(c, max(d, e))));
    int m = min(a, min(b, min(c, min(d, e))));
    printf("%d\n", M + m);
    exit(0);
}