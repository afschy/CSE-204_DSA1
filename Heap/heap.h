#include <vector>
using namespace std;

class Heap{
    int* container;
    int maxSize;
    int count;

    void swapIndex(int index1, int index2){
        int temp = container[index1];
        container[index1] = container[index2];
        container[index2] = temp;    
    }

    void max_heapify(int index){
        int leftChild = index<<1;
        int rightChild = leftChild|1;
        int largest = index;

        if(leftChild<=count && container[leftChild]>container[largest])
            largest = leftChild;
        if(rightChild<=count && container[rightChild]>container[largest])
            largest = rightChild;

        if(largest != index){
            swapIndex(index, largest);
            // print();
            max_heapify(largest);
        }
    }

    // void max_heapify_iter(int index){
    //     int leftChild, rightChild, largest;
    //     while(true){
    //         leftChild = index<<1;
    //         rightChild = leftChild|1;
    //         largest = index;

    //         if(leftChild<=count && container[leftChild]>container[largest])
    //             largest = leftChild;
    //         if(rightChild<=count && container[rightChild]>container[largest])
    //             largest = rightChild;

    //         if(largest != index){
    //             swapIndex(index, largest);
    //             // print();
    //             index = largest;
    //         }
    //         else
    //             break;
    //     }
    // }

    void percolate(int index){
        int parent = index>>1;
        if(!parent || !index) return;
        if(container[index] > container[parent]){
            swapIndex(index, parent);
            percolate(parent);
        }        
    }

    // void percolate_iter(int index){
    //     while(true){
    //         int parent = index>>1;
    //         if(!parent || !index) break;
    //         if(container[index] > container[parent]){
    //             swapIndex(index, parent);
    //             index = parent;
    //         }
    //         else
    //             break;
    //     }
    // }

    void resize(){
        maxSize = maxSize<<1;
        int* temp = new int[maxSize+1];
        for(int i=1; i<=count; i++)
            temp[i] = container[i];
        delete[] container;
        container = temp;
    }

public:
    Heap(int size){
        maxSize = size;
        container = new int[maxSize+1];
        count = 0;
    }

    Heap(const vector<int>& arr){
        maxSize = arr.size();
        container = new int[maxSize+1];
        for(int i=1; i<=maxSize; i++)
            container[i] = arr[i-1];
        count = maxSize;

        for(int i=maxSize>>1; i>=1; i--)
            max_heapify(i);
    }

    ~Heap(){
        delete[] container;
    }

    void insert(int value){
        if(count == maxSize){
            resize();
            //return;
        }
        container[++count] = value;
        percolate(count);
    }

    int size(){return count;}

    int getMax(){return container[1];}

    void deleteKey(){
        container[1] = container[count--];
        max_heapify(1);
    }

    // void print(){
    //     for(int i=1; i<=count; i++)
    //         cout<<container[i]<<" ";
    //     cout<<"\n";
    // }
};

void heapsort(vector<int>& v){
    Heap ob(v);
    for(int i=0; i<v.size(); i++){
        v[i] = ob.getMax();
        ob.deleteKey();
    }
}