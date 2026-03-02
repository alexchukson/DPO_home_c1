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

int rev(int *arr,int len)
{
    for (int i = 0; i < len; i++)
        if(i < len/2){
            if(i < len/4)
                SwapArr(arr, i, len/2-i-1);
            printf("%d ", arr[i]);
        }else{
            if(i < 3*len/4)
                SwapArr(arr, i, len - (i - len/2) - 1);
            printf("%d ", arr[i]);
        }
}

void invert_section(int arr[], int start, int end) {
    // Инверсия элементов в секции от start до end
    while (start < end) {
        SwapArr(arr, start, end);     
        // printf("%d ", arr[start]);
        start++;
        end--;
    }
}

void prnarr(int* arr, int len){
    for (int i = 0; i < len; i++) printf("%d " ,arr[i]);
    printf("\n");
}

int rev3(int *arr,int len)
{
    invert_section(arr, 0, 3);
    invert_section(arr, 4, 7);
    invert_section(arr, 8, 11);
    prnarr(arr, len);
}

void rshift(int arr[], int len) {
    // Циклический сдвиг ВПРАВО на 1
    int last_element = arr[len-1];  // Сохраняем последний элемент
    
    // Сдвигаем все элементы вправо
    for (int i = len-1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    
    arr[0] = last_element;  // Последний элемент ставим на первое место
}

enum {ARR_SIZE = 10};
void main(){
    int arr[ARR_SIZE];
    Input(arr, ARR_SIZE);
    rshift(arr, ARR_SIZE);
    prnarr(arr, ARR_SIZE);
}