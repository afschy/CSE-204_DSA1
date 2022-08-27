#include <iostream>
#include "Stack.h"
using namespace std;
#define DEFAULT_CHUNK 16

template<typename type>
class ArrayStack: public Stack<type>{
    type* container;
    int maxSize;
    int top;
    int direction;
    bool isShared;
    
    void reSize(){
        type* temp = new type[maxSize*2];
        if(direction == 1){
            for(int i=0; i<top; i++)
                temp[i] = container[i];
        }
        else{
            for(int i=0; i<top; i++)
                temp[maxSize*2-1-i] = container[maxSize-1-i];
        }
        maxSize*=2;
        delete[] container;
        container = temp;
    }
public:
    ArrayStack(int dir=1, int chunk=DEFAULT_CHUNK){
        maxSize = chunk;
        container = new type[maxSize];
        direction = dir;
        top = 0;
        isShared = false;
    }

    ArrayStack(type* arr, int arrLength, int dir=1, bool shared=false, int chunk=DEFAULT_CHUNK){
        isShared = shared;
        if(!shared){
            maxSize = chunk;
            container = new type[maxSize];
            direction = dir;
            top = 0;
            if(direction == 1){
                for(int i=0; i<arrLength; i++){
                    container[i] = arr[i];
                    top++;
                }
            }
            else{
                for(int i=0; i<arrLength; i++){
                    container[maxSize-1-i] = arr[i];
                    top++;
                }
            }
        }
        else{
            maxSize = arrLength;
            container = arr;
            direction = dir;
            top = 0;
        }
    }

    ~ArrayStack(){
        if(!isShared)
            delete[] container;
    }
    void clear(){top = 0;}

    void push(const type& item){
        if(top == maxSize)
            reSize();
        
        if(direction == 1)
            container[top++] = item;
        else
            container[maxSize-1-top++] = item;
    }

    type pop(){
        if(direction==1)
            return container[--top];
        else
            return container[maxSize-1-(--top)];
    }

    type topValue(){
        if(direction == 1)
            return container[top-1];
        else
            return container[maxSize-top];
    }

    int length(){return top;}
    void setDirection(int dir){
        if(top==0)
            direction = dir;
    }
};