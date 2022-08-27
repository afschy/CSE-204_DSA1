#include <iostream>
#include "List.h"
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
class LinkedList: public List<type>{
    Node<type>* head;
    Node<type>* tail;
    Node<type>* curr;
    int size;

public:
    LinkedList(){
        head = tail = curr = new Node<type>();
        size = 0;
    }
    LinkedList(const type* arr, int arrLength){
        head = tail = curr = new Node<type>();
        for(int i=arrLength-1;i>=0;i--)
            this->insert(arr[i]);
    }

    ~LinkedList(){
        while(head != NULL){
            curr = head;
            head = head->next;
            delete curr;
        }
    }

    void clear(){
        while(head != NULL){
            curr = head;
            head = head->next;
            delete curr;
        }
        head = tail = curr = new Node<type>();
        size = 0;
    }

    void insert(const type& item){
        curr->next = new Node<type>(item, curr->next);
        if (tail == curr) tail = curr->next;
        size++;
    }

    void append(const type& item){
        tail->next = new Node<type>(item, NULL);
        tail = tail->next;
        size++;
    }

    type remove(){
        type retVal = (curr->next)->element;
        Node<type>* nodeToDelete = curr->next;
        if(tail == curr->next)
            tail = curr;
        curr->next = (curr->next)->next;
        size--;
        delete nodeToDelete;
        return retVal;
    }

    void moveToStart(){curr = head;}

    void moveToEnd(){
        curr = head;
        while(curr->next != tail)
            curr = curr->next;
    }

    void prev(){
        if(curr != head){
            Node<type>* temp = head;
            while(temp->next != curr)
                temp = temp->next;
            curr = temp;
        }
    }

    void next(){
        if(curr != tail)
            curr = curr->next;
    }

    int length(){return size;}

    int currPos(){
        int index = 0;
        Node<type>* temp = head;
        while(temp != curr){
            index++;
            temp = temp->next;
        }
        return index;
    }

    void moveToPos(int pos){
        curr = head;
        for(int i=0;i<pos;i++)
            curr = curr->next;
    }

    type getValue(){
        return (curr->next)->element;
    }

    int Search(const type& item){
        Node<type>* temp = head;
        for(int i=0;i<size;i++){
            if((temp->next)->element == item)
                return i;
            temp = temp->next;
        }
        return -1;
    }
};