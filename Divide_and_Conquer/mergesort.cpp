void mergesort(int* arr, int* temp, int left, int right){
    if(right-left <= 1) return;
    int partition = (left+right) >> 1;
    mergesort(arr, temp, left, partition);
    mergesort(arr, temp, partition, right);

    for(int i=left,j=partition,index=left; index<right; index++){
        if(i==partition || (j<right && arr[j]<arr[i]))
            temp[index] = arr[j++];
        else 
            temp[index] = arr[i++];
    }

    for(int i=left; i<right; i++)
        arr[i] = temp[i];
}