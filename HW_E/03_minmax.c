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

int PosMin(int *arr,int len)
{
    int min=arr[0],i,pos=0;
    for (i = 1; i < len; i++)
        if (min > arr[i]) 
        {
            min = arr[i];
            pos = i;
        }
    return pos+1; 
}

int Max(int *arr,int len)
{
    int max=arr[0],i;
    for (i = 1; i < len; i++)
        if (max < arr[i]) 
            max = arr[i];
    return max; 
}

int PosMax(int *arr,int len)
{
    int max=arr[0],i,pos=0;
    for (i = 1; i < len; i++)
        if (max < arr[i]) 
        {
            max = arr[i];
            pos = i;
        }
    return pos+1; 
}

enum {ARR_SIZE = 10};
void main(){
    int arr[ARR_SIZE];
    Input(arr, ARR_SIZE);
    printf("%d %d %d %d \n", 
        PosMax(arr, ARR_SIZE),
        Max(arr, ARR_SIZE),
        PosMin(arr, ARR_SIZE),
        Min(arr, ARR_SIZE)
    ); 
}