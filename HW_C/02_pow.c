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

void main(){
    int n = 0, p = 0;
    scanf("%d %d", &n, &p);
    printf("%d\n", power(n, p));
    exit(0);
}