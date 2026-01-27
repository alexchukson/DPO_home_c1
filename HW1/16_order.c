#include <stdio.h>
int max(int a, int b){
    return a > b ? a : b;
}

int min(int a, int b){
    return a < b ? a : b;
}

void main(){
    int a = 0, b = 0, c = 0;
    int res = 0;
    scanf("%d%d%d", &a, &b, &c);
    res = a < b && b < c;
    printf("%s\n", res > 0 ? "YES" : "NO");
    exit(0);
}