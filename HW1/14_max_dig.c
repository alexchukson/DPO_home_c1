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
    scanf("%d", &a);
    int d100 = a/100;
    int d10 = (a/10) % 10;
    int d1 = a%10;
    printf("%d\n", max(d100,  max(d10, d1)));
    exit(0);
}