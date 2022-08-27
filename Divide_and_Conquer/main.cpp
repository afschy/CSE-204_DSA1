#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>
#include <algorithm>
#include "mergesort.cpp"
#include "quicksort.cpp"
#include "quicksort_random.cpp"
#include "insertion.cpp"
#define SEED 1007
#define TEST_NUM 20

int main(){
    std::ofstream fout;
    fout.open("1905081_report.csv");
    fout<<",Time required in ms\n";
    fout<<"n,Merge Sort,Quicksort,Randomized Quicksort,Insertion Sort,Quicksort with Sorted Input,";
    fout<<"Randomized Quicksort with Sorted Input,STL sort() function\n";
    srand(SEED);

    // clock_t programStart = clock();
    int n[] = {5,10,100,1000,10000,100000};
    int **sortingArr = new int*[5];

    for(int t=0; t<6; t++){
        fout<<n[t];
        auto start = std::chrono::high_resolution_clock::now();
        auto end = start;
        double timer[7] = {0.0};
        for(int i=0; i<5; i++){
            sortingArr[i] = new int[n[t]];
        }
        int* mergeTemp = new int[n[t]];

        for(int i=0; i<TEST_NUM; i++){
            for(int j=0; j<n[t]; j++)
                sortingArr[0][j]=sortingArr[1][j]=sortingArr[2][j]=sortingArr[3][j]=sortingArr[4][j] = rand();

            // For Merge Sort
            start = std::chrono::high_resolution_clock::now();
            mergesort(sortingArr[0], mergeTemp, 0, n[t]);
            end = std::chrono::high_resolution_clock::now();
            timer[0] += std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();

            // For Quicksort
            start = std::chrono::high_resolution_clock::now();
            quicksort(sortingArr[1], 0, n[t]);
            end = std::chrono::high_resolution_clock::now();
            timer[1] += std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();

            // For Randomized Quicksort
            start = std::chrono::high_resolution_clock::now();
            quicksort_random(sortingArr[2], 0, n[t]);
            end = std::chrono::high_resolution_clock::now();
            timer[2] += std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();

            // For Insertion Sort
            start = std::chrono::high_resolution_clock::now();
            insertionsort(sortingArr[3], 0, n[t]);
            end = std::chrono::high_resolution_clock::now();
            timer[3] += std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();

            // For Quicksort with Sorted Input
            start = std::chrono::high_resolution_clock::now();
            quicksort(sortingArr[3], 0, n[t]);
            end = std::chrono::high_resolution_clock::now();
            timer[4] += std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();

            // For Randomized Quicksort with Sorted Input
            start = std::chrono::high_resolution_clock::now();
            quicksort_random(sortingArr[3], 0, n[t]);
            end = std::chrono::high_resolution_clock::now();
            timer[5] += std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();

            // For STL sort() function
            start = std::chrono::high_resolution_clock::now();
            std::sort(sortingArr[4], sortingArr[4]+n[t]);
            end = std::chrono::high_resolution_clock::now();
            timer[6] += std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();
        }

        for(int i=0; i<7; i++)
            fout<<","<<(timer[i]/double(TEST_NUM))/1000000.00;
        fout<<"\n";
        
        for(int i=0; i<5; i++)
            delete[] sortingArr[i];
        delete[] mergeTemp;
    }

    fout.close();
    // std::cout<<1.00*(clock()-programStart)/CLOCKS_PER_SEC;
    return 0;
}