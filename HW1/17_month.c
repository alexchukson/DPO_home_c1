#include <stdio.h>
int max(int a, int b){
    return a > b ? a : b;
}

int min(int a, int b){
    return a < b ? a : b;
}

void main(){
    int month = 0;
    int res = 0;
    scanf("%d", &month);
    if (month >= 1 && month < 3)
        printf("winter\n");
    else if (month >= 3 && month < 6)
        printf("spring\n");
    else if (month >= 6 && month < 9)
        printf("summer\n");
    else if (month >= 9 && month < 12)
        printf("autumn\n");
    else if (month == 12)
        printf("winter\n");
    else
        printf("error\n");
    
    exit(0);
}