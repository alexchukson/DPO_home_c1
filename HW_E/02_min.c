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

int Min(int *arr,int len)
{
    int min=arr[0],i;
    for (i = 1; i < len; i++)
        if (min > arr[i]) 
            min = arr[i];
    return min; 
}


enum {ARR_SIZE = 5};
void main(){
    int arr[ARR_SIZE];
    Input(arr, ARR_SIZE);
    printf("%d \n", Min(arr, ARR_SIZE));
}