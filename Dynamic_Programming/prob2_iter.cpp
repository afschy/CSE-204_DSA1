#include <iostream>
#include <algorithm>
#define UNDEFINED -1

void memory_init(int* &memory, int n){
    int len = 1<<n;
    memory = new int[len];
    for(int i=0; i<len; i++)
        memory[i] = UNDEFINED;
}

int get_base_cost(int** cost, int n, int currPos, unsigned int state){
    int baseCost = cost[currPos][currPos];
    for(int i=0; i<n; i++){
        if(i!=currPos && (state&(1<<i))!=0)
            baseCost += cost[currPos][i];
    }
    return baseCost;
}

void populate_memory(int* memory, int** cost, int n){
    int finalPoint = (1<<n)-1;
    memory[finalPoint] = 0;
    
    for(int state=finalPoint-1; state>=0; state--){
        for(int currPos=0; currPos<n; currPos++){
            if((state&(1<<currPos)) != 0)
                continue;
            
            int baseCost = get_base_cost(cost, n, currPos, state);
            
            if(memory[state] == UNDEFINED)
                memory[state] = baseCost + memory[state|(1<<currPos)];
            else
                memory[state] = std::min(memory[state], baseCost + memory[state|(1<<currPos)]);
        }
    }
}

int main(){
    int n;
    std::cin>>n;

    int* memory;
    memory_init(memory, n);

    int** cost = new int*[n];
    for(int i=0; i<n; i++)
        cost[i] = new int[n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            std::cin>>cost[i][j];
    }

    populate_memory(memory, cost, n);
    std::cout<<memory[0]<<"\n";

    for(int i=0; i<n; i++){
        delete[] cost[i];
    }
    delete[] cost;
    delete[] memory;
    return 0;
}