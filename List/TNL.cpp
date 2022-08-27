#include <iostream>
#include "Arr.cpp"
#include "LL.cpp"
using namespace std;

int numberOfDigits(int num){
    if(num == 0) return 1;
    int n = 0;
    while(num){
        n++;
        num /= 10;
    }
    return n;
}

void showAll(int k, List<int>* b, List<int>* t){
    for(int i=0;i<k;i++){
        cout<<i;
        if(i < k-1) cout<<",";
    }
    cout<<"\n";

    for(int i=0;i<k;i++){
        if(b->Search(i) == -1){
            for(int j=0; j<numberOfDigits(i); j++)
                cout<<" ";
        }
        else
            cout<<i;
        if(i < k-1) cout<<",";
    }
    cout<<"\n";

    for(int i=0;i<k;i++){
        if(t->Search(i) == -1){
            for(int j=0; j<numberOfDigits(i); j++)
                cout<<" ";
        }
        else
            cout<<i;
        if(i < k-1) cout<<",";
    }
    cout<<"\n";
}

int main(){
    int k,l,m;
    cin>>k;

    cin>>l;
    int* b = new int[l];
    for(int i=0; i<l; i++)
        cin>>b[i];
    
    cin>>m;
    int* t = new int[m];
    for(int i=0; i<m; i++)
        cin>>t[i];

    List<int>* busList = new ArrayList<int>(b,l);
    List<int>* trainList = new ArrayList<int>(t,m);

    int task;
    bool flag = true;
    while(flag){
        cin>>task;
        switch (task)
        {
        case 0:
            flag = false;
            break;
        case 1:
            showAll(k, busList, trainList);
            break;
        default:
            break;
        }
    }

    delete[] b;
    delete[] t;
    delete busList;
    delete trainList;
}