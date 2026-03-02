#include <stdio.h>
int Input(int* arr, int n) 
{
    int i;
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    return i;
}

float avg(int* arr, int n) 
{
    float res = 0;
    for(int i = 0; i < n; i++)
        res += arr[i];
    return res/n;
}

enum {ARR_SIZE = 5};
void main(){
    int arr[ARR_SIZE];
    Input(arr, ARR_SIZE);
    printf("%f \n", avg(arr, ARR_SIZE));
}