#include <utility>
#include <cstdlib>

void quicksort_random(int* arr, int left, int right){
    if(right-left <= 1) return;
    int randomIndex = left + rand()%(right-left);
    std::swap(arr[randomIndex], arr[right-1]);

    int properIndex = left;
    for(int j=properIndex; j<right-1; j++){
        if(arr[j] <= arr[right-1])
            std::swap(arr[properIndex++], arr[j]);
    }
    std::swap(arr[properIndex], arr[right-1]);

    quicksort_random(arr, left, properIndex);
    quicksort_random(arr, properIndex+1, right);
}