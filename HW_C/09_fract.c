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

int convertSystem(int n, int p){
    int dig = 0;
    int res = 0;
    int por = 1;
    int ad = 0;
    while(n > 0){
        dig = n % p;
        n /= p;
        res += dig*por;
        por *= 10;
    }
    return res;
}

char* caps(char c){
    if(c >= 'a' && c <= 'z') //все символы лежат подряд ‘a’=97, ‘b’=98, ‘c’=99, ...
        return ('A' + (c-'a'));
    else
        return(c);
}

int fractional(int n){
    int res = 1;
    while(n > 0){
        res *= n;
        n--;
    }
    return res;
}

void printPrimeFactors(long long n) {
    // Делим на 2, пока число четное
    while (n % 2 == 0) {
        printf("2 ");
        n /= 2;
    }

    // Теперь n нечетное, начинаем с 3 и идем до sqrt(n)
    for (long long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            printf("%d ", i);
            n /= i;
        }
    }

    // Если n > 2, значит, n - простое число
    if (n > 2)
        printf("%d", n);
    printf("\n");
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    printPrimeFactors(n);
    return 0;
}
