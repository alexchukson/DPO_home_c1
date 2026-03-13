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

void sort_even_odd(int size, int a[])
{
    int noSwap;
    int a2[size];
    int a2_cnt = 0;
    int a1[size];
    int a1_cnt = 0;
    for (int i = 0; i < size; i++)
    {
        if ( a[i] % 2 == 0 ){
            a2[a2_cnt] = a[i]; a2_cnt++;
        }else{
            a1[a1_cnt] = a[i]; a1_cnt++;
        }
    }
    for (int i = 0; i < size; i++)
    {
        if ( i < a2_cnt ) a[i] = a2[i];
        else a[i] = a1[i-a2_cnt];
    }
}