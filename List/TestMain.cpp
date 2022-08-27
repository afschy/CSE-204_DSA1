#include <iostream>
#include "List.h"
#include "Arr.cpp"
#include "LL.cpp"
using namespace std;

template<typename type>
void print(List<type>* ls){
    int initCurr = ls->currPos();
    type val;
    ls->moveToStart();
    cout<<"<";
    for(int i=0; i<ls->length(); i++){
        if(i == initCurr) cout<<"| ";
        val = ls->getValue();
        cout<<val;
        ls->next();
        if(i != ls->length()-1)
            cout<<" ";
    }
    ls->moveToPos(initCurr);
    cout<<">\n";
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int k,x,i;
    cin>>k>>x;
    int *arr = new int[k];
    for(i=0; i<k; i++)
        cin>>arr[i];
    //Object Initialization
    //List<int>* ls = new ArrayList<int>(arr, k, x);
    List<int>* ls = new LinkedList<int>(arr, k);
    print(ls);

    int selection, parameter, retval;
    bool flag = true;
    while(flag){
        cin>>selection>>parameter;
        switch (selection)
        {
        case 0:
            flag = false;
            break;
        case 1:
            ls->clear();
            print(ls);
            cout<<"-1\n";
            break;
        case 2:
            ls->insert(parameter);
            print(ls);
            cout<<"-1\n";
            break;
        case 3:
            ls->append(parameter);
            print(ls);
            cout<<"-1\n";
            break;
        case 4:
            retval = ls->remove();
            print(ls);
            cout<<retval<<"\n";
            break;
        case 5:
            ls->moveToStart();
            print(ls);
            cout<<"-1\n";
            break;
        case 6:
            ls->moveToEnd();
            print(ls);
            cout<<"-1\n";
            break;
        case 7:
            ls->prev();
            print(ls);
            cout<<"-1\n";
            break;
        case 8:
            ls->next();
            print(ls);
            cout<<"-1\n";
            break;
        case 9:
            retval = ls->length();
            print(ls);
            cout<<retval<<"\n";
            break;
        case 10:
            retval = ls->currPos();
            print(ls);
            cout<<retval<<"\n";
            break;
        case 11:
            ls->moveToPos(parameter);
            print(ls);
            cout<<"-1\n";
            break;
        case 12:
            retval = ls->getValue();
            print(ls);
            cout<<retval<<"\n";
            break;
        case 13:
            retval = ls->Search(parameter);
            print(ls);
            cout<<retval<<"\n";
            break;
        default:
            break;
        }
    }

    delete[] arr;
    delete ls;
    return 0;
}