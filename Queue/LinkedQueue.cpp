#include <iostream>
#include "Queue.h"
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

template <typename type>
class LinkedQueue: public Queue<type>{
    Node<type>* front;
    Node<type>* rear;
    int size;

public:
    LinkedQueue(){
        front = rear = new Node<type>();
        size = 0;
    }

    ~LinkedQueue(){
        while(front != NULL){
            Node<type>* temp = front;
            front = front->next;
            delete temp;
        }
    }

    void clear(){
        while(front != NULL){
            Node<type>* temp = front;
            front = front->next;
            delete temp;
        }
        front = rear = new Node<type>();
        size = 0;
    }    

    void enqueue(const type& item){
        rear->next = new Node<type>(item, NULL);
        rear = rear->next;
        size++;
    }

    type dequeue(){
        type retval = (front->next)->element;
        Node<type>* temp = front;
        front = front->next;
        if(rear == temp) rear = front;
        delete temp;
        size--;
        return retval;
    }

    int length(){
        return size;
    }

    type frontValue(){
        return (front->next)->element;
    }

    type rearValue(){
        return rear->element;
    }

    type leaveQueue(){
        type retval = rear->element;
        Node<type>* temp = front;
        while(temp->next != rear)
            temp = temp->next;
        delete rear;
        rear = temp;
        rear->next = NULL;
        size--;
        return retval;
    }
};