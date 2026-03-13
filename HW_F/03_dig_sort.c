#include <stdio.h>
#include <stdlib.h>
void SwapArr(int *arr,int i,int j)
{
    int temp = arr[i];
    arr[i]   = arr[j];
    arr[j]   = temp;
}

void sort_array(int size, int a[])
{
    int noSwap;
    for (int i = 0; i < size; i++)
    {
        //printf("%d\n",i);
        noSwap = 1;
        for (int j = size-1; j > i; j--)
        {
            if(a[j-1]>a[j])
            {
                //printf("*,"); 
                SwapArr(a,j-1,j);
                noSwap = 0;
            }
        }
        //printf("\n");
        if(noSwap)
            break;
    }
}

// void sort_even_odd(int size, int a[])
// {
//     int noSwap;
//     int a2[size];
//     int a2_cnt = 0;
//     int a1[size];
//     int a1_cnt = 0;
//     for (int i = 0; i < size; i++)
//     {
//         if ( a[i] % 2 == 0 ){
//             a2[a2_cnt] = a[i]; a2_cnt++;
//         }else{
//             a1[a1_cnt] = a[i]; a1_cnt++;
//         }
//     }
//     for (int i = 0; i < size; i++)
//     {
//         if ( i < a2_cnt ) a[i] = a2[i];
//         else a[i] = a1[i-a2_cnt];
//     }
// }

void sort_dig(char* str)
{
    int d[1000];
    int cnt = 0;
    int dig[10] = {0,0,0,0,0,0,0,0,0};
    // if ( n == 0){
    //     printf("0 1 \n");
    //     return;
    // }
    cnt = strlen(str);
    for ( int i = 0; i < cnt; i++)
    {
        int num = str[i] - '0';
        d[i] =  num;
    }
    sort_array(cnt, d);
    for ( int i = 0; i < cnt; i++){
        for ( int j = 0; j < 10; j++)
            if ( d[i] == j ) dig[j]++;
    }
    for ( int j = 0; j < 10; j++)
        if ( dig[j] != 0)
            printf("%d %d \n", j, dig[j]);
}

void main(){
    char str[1000];
    scanf("%s", &str);
    sort_dig(str);
}