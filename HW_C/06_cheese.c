#include <stdio.h>
#include <stdint.h>      // Основной заголовочный файл
#include <inttypes.h>    // Для макросов вывода (PRIu64)

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

uint64_t  pow2(int  n){
    uint64_t res = 1;
    return res<<(n-1);
}

int main(){
    int  n = 0;
    uint64_t a = 0;
    scanf("%d", &n);
    a = pow2(n);
    printf("%" PRIu64 "\n", a);
    return 0;
}