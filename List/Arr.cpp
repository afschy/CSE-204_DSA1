#include <iostream>
#include "List.h"
using namespace std;
#define DEFAULT_CHUNK 16

template<typename type> 
class ArrayList: public List<type>{
private:
    type* container;
    int arrLength;
    int chunkSize;
    int currSize;
    int curr;

    void expand(){
        currSize += chunkSize;
        type *temp = new type[currSize];
        for (int i = 0; i < arrLength; i++)
            temp[i] = container[i];
        delete[] container;
        container = temp;
    }
public:
    ArrayList(int chunkSize = DEFAULT_CHUNK){
        this->chunkSize = chunkSize;
        container = new type[chunkSize];
        currSize = chunkSize;
        arrLength = 0;
        curr = 0;
    }
    ArrayList(const type* arr, int arrLength, int chunkSize = DEFAULT_CHUNK){
        this->chunkSize = chunkSize;
        container = new type[chunkSize];
        currSize = chunkSize;
        this->arrLength = arrLength;
        curr = 0;
        for(int i=0;i<arrLength;i++)
            container[i] = arr[i];
    }
    ~ArrayList(){
        delete[] container;
    }

    void clear(){
        delete[] container;
        container = new type[chunkSize];
        currSize = chunkSize;
        arrLength = 0;
        curr = 0;
    }

    void insert(const type& item){
        if(arrLength == currSize){
            expand();
        }

        for(int i=arrLength-1; i>=curr; i--){
            container[i+1] = container[i];
        }
        container[curr] = item;
        arrLength++;
    }

    void append(const type& item){
        if(arrLength == currSize)
            expand();
        container[arrLength++] = item; 
    }

    type remove(){
        type retVal = container[curr];
        for(int i=curr; i<arrLength-1; i++)
            container[i] = container[i+1];
        arrLength--;
        if(curr == arrLength)
            curr = max(0, arrLength-1);
        return retVal;
    }

    void moveToStart(){
        curr = 0;
    }

    void moveToEnd(){
        curr = arrLength - 1;
    }

    void prev(){
        if(curr > 0)
            curr--;
    }

    void next(){
        if(curr < arrLength-1)
            curr++;
    }

    int length(){return arrLength;}

    int currPos(){return curr;}

    void moveToPos(int pos){curr = pos;}

    type getValue(){
        return container[curr];
    }

    int Search(const type& item){
        for(int i=0; i<arrLength; i++){
            if(container[i] == item) return i;
        }
        return -1;
    }
};