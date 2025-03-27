#include<bits/stdc++.h>
using namespace std;




void dfs(int start,vector<list<int>>&adjL,vector<int>&visited){
    visited[start] = 1;
    for(auto neighbours: adjL[start]){
        if(!visited[neighbours]){
            dfs(neighbours,adjL,visited);
        }
    }
}

int numProvinces(vector<vector<int>> adj,int V){
    vector<list<int>> adjL(V);
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V;j++){
            if(adj[i][j] == 1 && i != j){
                adjL[i].push_back(j);
                adjL[j].push_back(i);
            }
        }
    }
    vector<int> visited(V, 0);
    int cnt = 0;
    for(int i = 0; i < V; i++){
        if(!visited[i]){
            cnt++;
            dfs(i, adjL, visited); 
        }
    }
    return cnt;
}

int main(){
    vector<vector<int>> adj
    {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };

    cout << numProvinces(adj,3);
}