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