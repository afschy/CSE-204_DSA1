#include <cstring>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
#define UNDEFINED -1

struct ResultContainer{ //For returning multiple-variable result only
    vector<int> distance;
    stack<int> path;
};

//n: number of sides of the dice
//X: total number of squares
//edges: array indicating snakes and ladders
ResultContainer BFS(const int n, const int X, const int* edges){
    int* parent = new int[X+1]();
    vector<int> distance(X+1);
    for(int i=0; i<=X; i++)
        distance[i] = UNDEFINED;

    queue<int> q;
    q.push(1);
    distance[1] = 0;

    while(q.size()){
        int curr = q.front();
        q.pop();
        int dest = edges[curr];
        if(dest){ //If there is a ladder or snake
            if(distance[dest]==UNDEFINED){ //Destination hasn't already been reached
                distance[dest] = distance[curr]; //Climbing or descending requires no dice roll
                parent[dest] = curr;
                q.push(dest);
            }
            continue; //Cannot roll dice when at the start point of a snake/ladder
        }

        for(int i=1; i<=n; i++){
            dest = curr+i;
            if(dest<=X && distance[dest]==UNDEFINED){ //Destination is valid and hasn't already been reached
                distance[dest] = distance[curr]+1;
                parent[dest] = curr;
                q.push(dest);
            }
        }
    }

    ResultContainer result;
    result.distance = distance;
    if(distance[X] != UNDEFINED){
        int curr = X;
        stack<int> path;
        while(curr){ //Pushing the entire path into the stack
            path.push(curr);
            curr = parent[curr];
        }
        result.path = path;
    }

    delete[] parent;
    return result;
}