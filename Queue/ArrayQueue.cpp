#include <iostream>
#include "Queue.h"
using namespace std;
#define DEFAULT_SIZE 2

template <typename type>
class ArrayQueue: public Queue<type>{
    int front;
    int rear;
    int maxSize;
    type* container;
    bool dontClear;

    void resize(){
        type* temp = new type[maxSize*2];
        int index = 1;
        int len = (rear+maxSize-front+1)%maxSize;
        for(int i=0; i<len; i++){
            temp[index++] = container[(front+i)%maxSize];
        }
        front = 1;
        rear = index-1;
        maxSize *= 2;
        delete[] container;
        container = temp;
    }
public:
    ArrayQueue(int size = DEFAULT_SIZE){
        rear = 0;
        front = 1;
        maxSize = size;
        container = new type[maxSize];
        dontClear = false;
    }

    ArrayQueue(type* arr, int arrLength, bool flag=false){
        container = arr;
        maxSize = arrLength;
        rear = 0;
        front = 1;
        dontClear = flag;
    }

    ~ArrayQueue(){
        if(!dontClear){
            delete[] container;
            // cout<<"Deleting\n";
        }
    }

    void clear(){
        delete[] container;
        container = new type[DEFAULT_SIZE];
        rear = 0;
        front = 1;
        maxSize = DEFAULT_SIZE;
    }

    void enqueue(const type& item){
        int len = (rear+maxSize-front+1)%maxSize;
        if(len == maxSize-1)
            resize();
        rear = (rear+1)%maxSize;
        container[rear] = item;
    }

    type dequeue(){
        type retval = container[front];
        front = (front+1)%maxSize;
        return retval;
    }

    int length(){return (rear+maxSize-front+1)%maxSize;}

    type frontValue(){return container[front];}
    type rearValue(){return container[rear];}

    type leaveQueue(){
        type retval = container[rear];
        rear = (rear-1)%maxSize;
        if(rear<0) rear += maxSize;
        return retval;
    }
};