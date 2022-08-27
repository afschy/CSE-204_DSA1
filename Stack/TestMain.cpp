#include <iostream>
#include "Arr.cpp"
#include "LL.cpp"

template <typename type>
void print(Stack<type>* st){
    type* arr = new type[st->length()];
    int index = 0;
    while(st->length())
        arr[index++] = st->pop();

    index--;
    cout<<"<";
    for(int i=index; i>=0; i--){
        cout<<arr[i]<<" ";
    }
    cout<<">\n";
    for(;index>=0;index--)
        st->push(arr[index]);

    delete[] arr;
}

int main(){
    Stack<int>* st = new ArrayStack<int>();
    //Stack<int>* st = new LinkedStack<int>();
    int n, input;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>input;
        st->push(input);
    }
    print(st);

    int param, retval;
    while(true){
        cin>>input>>param;
        if(!input) break;
        switch (input)
        {
        case 1:
            st->clear();
            print(st);
            cout<<"-1\n";
            break;
        case 2:
            st->push(param);
            print(st);
            cout<<"-1\n";
            break;
        case 3:
            retval = st->pop();
            print(st);
            cout<<retval<<"\n";
            break;
        case 4:
            retval = st->length();
            print(st);
            cout<<retval<<"\n";
            break;
        case 5:
            retval = st->topValue();
            print(st);
            cout<<retval<<"\n";
            break;
        case 6:
            st->setDirection(param);
            print(st);
            cout<<"-1\n";
            break;
        default:
            break;
        }
    }
}