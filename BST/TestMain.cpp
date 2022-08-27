#include <iostream>
#include <fstream>
#include <cstring>
#include "BST_LL.cpp"
using namespace std;

int main(){
    ifstream inFile("input.txt");
    // freopen("output.txt", "w", stdout);
    char type[12], arg[12];
    BST_LL<int> ob;

    while(true){
        inFile>>type>>arg;
        if(inFile.eof())
            break;
        
        if(!strcmp(type, "F")){
            int val = atoi(arg);
            if(ob.find(val))
                cout<<"True\n";
            else
                cout<<"False\n";
        }

        else if(!strcmp(type, "I")){
            int val = atoi(arg);
            ob.insert(val);
            ob.print();
        }

        else if(!strcmp(type, "T")){
            int* arr = ob.traverse(arg);
            for(int i=0; i<ob.size(); i++){
                cout<<arr[i];
                if(i != ob.size()-1)
                    cout<<" ";
            }
            delete[] arr;
            cout<<"\n";
        }

        else if(!strcmp(type, "D")){
            int val = atoi(arg);
            try{
                ob.remove(val);
            }catch(const char* msg){
                cout<<msg<<"\n";
                continue;
            }
            ob.print();
        }
    }
}