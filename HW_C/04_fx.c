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

int f(int x){
    if ( x < -2 ) return 4;
    else if ( x < 2 ) return x*x;
    else return x*x + 4*x + 5;
}

int max(int a, int b){
    return a > b ? a : b;
}

int main(){
    int c = -1;
    int fmax = -1e12;
    while( c != 0 ){
        scanf("%d", &c);
        fmax = max(fmax, f(c));
    }
    printf("%d\n", fmax);

    return 0;
}