#include <stdio.h>

int my_abs(int n){
    return n >= 0 ?  n: -n;
}

int power(int n, int p){
    int res = n;
    if ( p == 0 ) return 1;
    while( p > 1 ){
        // printf("p %d \n", p);
        res *= n;
        p--;
    }
    return res;
}

int middle(int a, int b){
    return (a + b)/2;
}

void main(){
    int a = 0, b = 0;
    scanf("%d %d", &a, &b);
    printf("%d\n", middle(a, b));
    exit(0);
}