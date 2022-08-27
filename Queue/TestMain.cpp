#include <iostream>
#include "ArrayQueue.cpp"
#include "LinkedQueue.cpp"

template <typename type>
void print(Queue<type>* q){
    cout<<"<";
    type* arr = new type[q->length()];
    int index = 0;
    while(q->length()){
        arr[index] = q->dequeue();
        cout<<arr[index];
        index++;
        if(q->length()) cout<<", ";
    }
    cout<<">\n";

    for(int i=0; i<index; i++)
        q->enqueue(arr[i]);
    delete[] arr;
}

int main(){
    int n;
    cin>>n;
    int input;
    Queue<int>* q = new LinkedQueue<int>();
    for(int i=0; i<n; i++){
        cin>>input;
        q->enqueue(input);
    }
    print(q);

    int choice, param, retval;
    while(true){
        cin>>choice>>param;
        if(!choice)
            break;
        
        switch (choice){
        case 1:
            q->clear();
            print(q);
            cout<<"-1\n";
            break;
        case 2:
            q->enqueue(param);
            print(q);
            cout<<"-1\n";
            break;
        case 3:
            retval = q->dequeue();
            print(q);
            cout<<retval<<"\n";
            break;
        case 4:
            retval = q->length();
            print(q);
            cout<<retval<<"\n";
            break;
        case 5:
            retval = q->frontValue();
            print(q);
            cout<<retval<<"\n";
            break;
        case 6:
            retval = q->rearValue();
            print(q);
            cout<<retval<<"\n";
            break;
        case 7:
            retval = q->leaveQueue();
            print(q);
            cout<<retval<<"\n";
            break;
        
        default:
            break;
        }
    }

    delete q;
}