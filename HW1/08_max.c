#include <stdio.h>
int max(int a, int b){
    return a > b ? a : b;
}

void main(){
    int a = 0, b = 0, c = 0;
    // printf("Enter 3 int numbers: \n");
    scanf("%d%d%d", &a, &b, &c);

    printf("%d\n", max(a, max(b, c)));
    exit(0);
}