#include <iostream>
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

long long solve(int n, int k, int* price){
    quicksort_random(price, 0, n);
    long long total=0, multiplier=0;
    for(int i=0; i<n; i++){
        if(i%k == 0)
            multiplier++;
        total += price[n-1-i]*multiplier;
    }
    return total;
}

int main(){
    int n, k;
    std::cin>>n>>k;
    int* price = new int[n];
    for(int i=0; i<n; i++)
        std::cin>>price[i];
    std::cout<<solve(n, k, price);
    delete[] price;
    return 0;
}