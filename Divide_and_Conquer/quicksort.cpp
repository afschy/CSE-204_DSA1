#include <utility>

void quicksort(int* arr, int left, int right){
    if(right-left <= 1) return;

    int properIndex = left;
    for(int j=properIndex; j<right-1; j++){
        if(arr[j] <= arr[right-1])
            std::swap(arr[properIndex++], arr[j]);
    }
    std::swap(arr[properIndex], arr[right-1]);

    quicksort(arr, left, properIndex);
    quicksort(arr, properIndex+1, right);
}