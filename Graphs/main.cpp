#include <iostream>
#include "graph.cpp"
using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin>>t;

    while(t--){
        int n,X;
        cin>>n>>X;
        int* edges = new int[X+1](); //Init with 0, which means no snake/ladder at that point

        int l,s,u,v;
        cin>>l;
        while(l--){
            cin>>u>>v;
            edges[u] = v;
        }
        cin>>s;
        while(s--){
            cin>>u>>v;
            edges[u] = v;
        }

        ResultContainer result = BFS(n, X, edges);
        cout<<result.distance[X]<<"\n";
        if(result.distance[X] == UNDEFINED) //The last square never reached
            cout<<"No solution\n";
        else{ //Printing path
            while(result.path.size()){
                cout<<result.path.top();
                result.path.pop();
                if(result.path.size())
                    cout<<" -> ";
            }
            cout<<"\n";
        }
        
        bool flag = false; //Flag for determining if any unreachable square exists
        for(int i=1; i<=X; i++){ //Printing unreachables
            if(result.distance[i] == UNDEFINED){
                cout<<i<<" ";
                flag = true;
            }
        }
        if(!flag)
            cout<<"All reachable";
        cout<<"\n";
        if(t)
            cout<<"\n";

        delete[] edges;
    }

    return 0;
}