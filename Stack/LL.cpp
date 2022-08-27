#include <iostream>
#include "Stack.h"
using namespace std;

template<typename type>
class Node{
public:
    type element;
    Node* next;
    Node(Node* next = NULL){this->next = next;}
    Node(const type& element, Node* next = NULL){
        this->element = element;
        this->next = next;
    }
};

template<typename type>
class LinkedStack: public Stack<type>{
    Node<type>* top;
    int size;
public:
    LinkedStack(){
        top = NULL;
        size = 0;
    }

    LinkedStack(const type* arr, int arrLength){
        for(int i=0; i<arrLength; i++)
            top = new Node<type>(arr[i], top);
        size = arrLength;
    }

    ~LinkedStack(){clear();}

    void clear(){
        while(top != NULL){
            Node<type>* temp = top;
            top = top->next;
            delete temp;
        }
        size = 0;
    }

    void push(const type& item){
        top = new Node<type>(item, top);
        size++;
    }

    type pop(){
        type retval = top->element;
        Node<type>* temp = top;
        top = top->next;
        delete temp;
        size--;
        return retval;
    }

    type topValue(){return top->element;}

    int length(){return size;}

    void setDirection(int direction){}
};