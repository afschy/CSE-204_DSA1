#include <iostream>
#include "ArrayQueue.cpp"
#include "LinkedQueue.cpp"
using namespace std;

struct customer{
    int id;
    int time;
    int cost;
};

int main(){
    int n;
    cin>>n;
    customer* input = new customer[n];
    for(int i=0; i<n; i++){
        cin>>input[i].time>>input[i].cost;
        input[i].id = i+1;
    }
    
    bool serving[] = {false, false};
    int currTime = 0, index = 0;
    int freeAt[2] = {-1,-1}, endTime[2] = {0,0};
    ArrayQueue<customer> booth[2];
    // LinkedQueue<customer> booth[2];

    for(currTime=0; ; currTime++){
        for(int i=0; i<2; i++){
            // Serving a customer has ended
            if(serving[i] && currTime == freeAt[i]){
                serving[i] = false;
                booth[i].dequeue();
                endTime[i] = currTime;
            }
        }
        
        // Take in new customer at specified time
        while(index<n && currTime == input[index].time){
            if(booth[0].length() <= booth[1].length())
                booth[0].enqueue(input[index]);

            /* This block of code is for forcing the program to match the arbitrary
            selection of the second queue at time = 10 in the given example */
            // else if(booth[0].length() == booth[1].length()){
            //     if(currTime == 10)
            //         booth[1].enqueue(input[index]);
            //     else
            //         booth[0].enqueue(input[index]);
            // }

            else
                booth[1].enqueue(input[index]);
            index++;
        }
        
        for(int i=0;i<2;i++){
            // Switch booth
            int otherBooth = i^1;
            if(booth[i].length()-1 > booth[otherBooth].length()){
                customer switcher = booth[i].leaveQueue();
                booth[otherBooth].enqueue(switcher);
                // cout<<switcher.id<<" switching from "<<i+1<<" to "<<otherBooth+1<<" at "<<currTime<<endl;
            }
            
            // Start serving new customer if not already serving
            if(!serving[i] && booth[i].length()){
                serving[i] = true;
                freeAt[i] = currTime + booth[i].frontValue().cost;
            }
        }

        // break if queues are empty and no new customer will come
        if(!booth[0].length() && !booth[1].length() && index==n)
            break;
    }

    cout<<"Booth 1 finishes service at t = "<<endTime[0]<<"\n";
    cout<<"Booth 2 finishes service at t = "<<endTime[1]<<"\n";

    delete[] input;
    // delete[] booth;
    return 0;
}