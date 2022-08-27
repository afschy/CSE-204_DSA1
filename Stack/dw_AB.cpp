#include <iostream>
#include <algorithm>
#include "Arr.cpp"
#include "LL.cpp"
using namespace std;

struct Dish{
    int friendNum;
    int time;
    int course;

    Dish(int f=0, int t=0, int c=0){
        friendNum = f;
        time = t;
        course = c;
    }
    bool operator==(const Dish& ob){
        return (friendNum==ob.friendNum) && (time==ob.time) && (course==ob.course);
    }
};

int main(){
    int n, x;
    cin>>n>>x;
    int* timePerDish = new int[x];
    for(int i=0; i<x; i++) cin>>timePerDish[i];

    //Storing all inputs
    int k, t, s, inputCount=0;
    Dish* inputs = new Dish[n*x];
    while(true){
        cin>>k;
        if(k==0)break;
        cin>>t>>s;
        Dish newDish(k,t,s);
        inputs[inputCount++] = newDish;
    }

    //Stack Initialization
    Stack<Dish>* dirty = new ArrayStack<Dish>();
    Stack<Dish>* clean = new ArrayStack<Dish>();
    Stack<int>* full = new ArrayStack<int>();
    // Stack<Dish>* dirty = new LinkedStack<Dish>();
    // Stack<Dish>* clean = new LinkedStack<Dish>();
    // Stack<int>* full = new LinkedStack<int>();
    
    int* endTimes = new int[n*x];
    int endPoint = 0, inPoint = 0;
    bool isBusy = false;
    Dish currDish;
    int currTime;
    for(currTime=0;;currTime++){
        //Inserting dirty dish into stack if it is time
        if(inputs[inPoint].time == currTime){
            Dish newDish = inputs[inPoint];
            inPoint++;
            dirty->push(newDish);
            if(newDish.course == x)
                full->push(newDish.friendNum);
        }

        if(isBusy == false && dirty->length()){
            currDish = dirty->pop();
            currDish.time = currTime + timePerDish[currDish.course-1] - 1;
            isBusy = true;
        }
        if(currDish.time == currTime){
            isBusy = false;
            clean->push(currDish);
            endTimes[endPoint++] = currTime;
        }

        if(inPoint == inputCount && isBusy == false && dirty->length() == 0)
            break;
    }
    
    //Printing results
    cout<<currTime<<endl;
    for(int i=0; i<endPoint; i++){
        cout<<endTimes[i];
        if(i<endPoint-1)
            cout<<",";
    }
    cout<<"\n";
    (full->length()==n)? cout<<"Y\n" : cout<<"N\n";
    while(full->length()){
        cout<<full->pop();
        if(full->length())
            cout<<",";
    } 
    cout<<"\n";

    delete[] timePerDish;
    delete[] inputs;
    delete[] endTimes;
    delete dirty;
    delete clean;
    delete full;
    return 0;
}