#include <stdio.h>
int max(int a, int b){
    return a > b ? a : b;
}

int min(int a, int b){
    return a < b ? a : b;
}

void main(){
    int a = 0, b = 0;
    scanf("%d%d", &a, &b);
    if (a > b)
        printf("Above\n");
    else if (a < b)
        printf("Less\n");
    else 
        printf("Equal\n");
    
    exit(0);
}