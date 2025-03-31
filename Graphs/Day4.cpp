#include<bits/stdc++.h>
using namespace std;
using namespace std;


// Detect cycle in undirected graph using BFS
// bool detect(int i,vector<vector<int>>& adj,vector<int>& vis){
//     vis[i] = 1;
//     queue<pair<int,int>> q;
//     q.push({i, -1}); 
//     while(!q.empty()){
//             int node = q.front().first;
//             int parent = q.front().second;
//             q.pop();
//             for(auto neighbours: adj[node]){
//                 if(!vis[neighbours]){
//                     vis[neighbours] = 1;
//                     q.push({neighbours, node});
//                 }else if(neighbours != parent){
//                     return true; // Cycle detected
//                 }
//           }
//     }
//     return false;

// }


// bool isCycle(vector<vector<int>>adj) {
//     // initialise them as unvisited 
//     vector<int> visited(adj.size(), 0);
//     for(int i = 0;i< adj.size();i++) {
//         if(!visited[i]) {
//             if(detect(i, adj, visited)) return true; 
//         }
//     }
//     return false; 
// }


// // cycle detection in directed graph using DFS

bool dfs(int i, int parent,vector<vector<int>>&adj, vector<int>&vis){
    vis[i] = 1;
    for(auto neighbours: adj[i]){
        if(!vis[neighbours])
        {
            if(dfs(neighbours, i, adj, vis)){
                return true;
            }
        }else if(parent != neighbours){
            return true;
        }
    }
    return false;
}


bool isCycle(vector<vector<int>> adj){
    vector<int> visited(adj.size(), 0);
    for(int i = 0; i < adj.size(); i++){
        if(!visited[i]){
            if(dfs(i, -1, adj, visited)){
                return true;
            }
        }
    }
    return false;
}
int main(){
    // vector<vector<int>> adjL = {{1}, {0,2,4}, {1,3}, {2,4}, {1,3}};
    vector<vector<int>> adjL = {{1}, {0,2,4}, {1,3}, {2,4},{1,3}};
    bool ans = isCycle(adjL);
    if(ans){
        cout << "Cycle is present" << endl;
    }else{
        cout << "Cycle is not present" << endl;
    }
}


