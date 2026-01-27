#include <stdio.h>
int max(int a, int b){
    return a > b ? a : b;
}

int min(int a, int b){
    return a < b ? a : b;
}

void main(){
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    float k = 0, b = 0;
    float dy = 0, dx = 0;
    // printf("Enter 3 int numbers: \n");
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    if (x1 != x2){
        dy = y2 - y1;
        dx = x2 - x1;
        k = dy/dx;
        b = y1 - k*x1;
    }
    printf("%.2f %.2f\n", k, b);
    exit(0);
}