#include <stdio.h>

void main(){
    int a = 0, b = 0, c = 0;
    printf("Enter 3 int numbers: \n");
    scanf("%d%d%d", &a, &b, &c);
    printf("The sum of three integers = %d \n", a + b + c);
    exit(0);
}