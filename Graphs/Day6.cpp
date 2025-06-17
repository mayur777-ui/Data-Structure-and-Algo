//connectedComponents
#include<bits/stdc++.h>
using namespace std;



void dfs(vector<int>&component,int node, unordered_set<int> visited, unordered_map<int,vector<int>> adj){
    visited.insert(node);
    component.push_back(node);
    for(auto it: adj[node]){
        if(!visited.count(it)){
            dfs(component,it, visited,adj);
        }
    }
}
int main(){
    vector<pair<int, int>> edges = {
        {100, 200}, {200, 300}, {400, 500}, {600, 700}, {900, 900}
    };

    unordered_map<int, vector<int>> adj;
    unordered_set<int> nodes;

    for(auto [u,v] : edges){
        adj[u].push_back(v);
        adj[v].push_back(u);
        nodes.insert(u);
        nodes.insert(v);
    }


    unordered_set<int> visited;
    vector<vector<int>> connectedComponent;
    int numberOfConnection = 0;
    for(auto node: nodes){
        if(!visited.count(node)){
            vector<int>component;
            dfs(component,node,visited,adj);
            numberOfConnection++;
            connectedComponent.push_back(component);
        }
    }

    cout << "Number of connected component: " << numberOfConnection; 

    cout << "Connected Components:\n";
    for (const auto &comp : connectedComponent) {
        for (int node : comp) {
            cout << node << " ";
        }
        cout << "\n";
    }


}