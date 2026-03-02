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

void SwapArr(int *arr,int i,int j)
{
    int temp = arr[i];
    arr[i]   = arr[j];
    arr[j]   = temp;
}

void BubbleSort(int* arr,int n)
{
    int noSwap;
    for (int i = 0; i < n; i++)
    {
        //printf("%d\n",i);
        noSwap = 1;
        for (int j = n-1; j > i; j--)
        {
            if(arr[j-1]>arr[j])
            {
                //printf("*,"); 
                SwapArr(arr,j-1,j);
                noSwap = 0;
            }
        }
        //printf("\n");
        if(noSwap)
            break;
    }
}

int SumPos(int *arr,int len)
{
    int sum = 0;
    for (int i = 0; i < len; i++)
        if (arr[i] > 0) sum += arr[i];
    return sum; 
}

enum {ARR_SIZE = 10};
void main(){
    int arr[ARR_SIZE];
    Input(arr, ARR_SIZE);
    printf("%d \n", SumPos(arr, ARR_SIZE));
}