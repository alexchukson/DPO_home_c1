
 int find_max_array(int size, int a[]){
    int MAX = a[0];
    for ( int i = 1; i < size; i++){
        if ( a[i] > MAX) MAX = a[i];
    }
    return MAX;
 }
