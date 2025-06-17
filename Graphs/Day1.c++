#include <bits/stdc++.h>
using namespace std;

// // Graph representation ->1.Adjacency Matrix
void updateAdjacencyMatrix(vector<vector<int>>& adjMatrix, int u, int v) {
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
    cout << "Edge added between node " << u << " and node " << v << "." << endl;
}

int main() {
    int nodes, edges;

    cout << "Welcome to the Adjacency Matrix Generator!" << endl;
    cout << "Enter the number of nodes and edges: ";
    cin >> nodes >> edges;

    
    vector<vector<int>> adjMatrix(nodes, vector<int>(nodes, 0));
    cout << "Initialized adjacency matrix with " << nodes << " nodes." << endl;

   
    cout << "Please enter the edges (node pairs u and v) one by one:" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cout << "Edge " << i + 1 << ": ";
        cin >> u >> v;

        
        if (u >= 0 && u < nodes && v >= 0 && v < nodes) {
            updateAdjacencyMatrix(adjMatrix, u, v);
        } else {
            cout << "Invalid edge: (" << u << ", " << v << "). Please try again!" << endl;
            i--; 
        }
    }

    cout << "\nFinal Adjacency Matrix:" << endl;
    for (const auto& row : adjMatrix) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }

    cout << "Adjacency matrix generation complete. Thank you!" << endl;
    return 0;
}



// // Graph representation ->2.Aadjacency list 

void updateAdjacencyList(vector<list<int>>&adjList,int u,int v){
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}


int main(){
    int nodes, edges;

    cout << "Welcome to the Adjacency List Generator!" << endl;
    cout << "Enter the number of nodes and edges: ";
    cin >> nodes >> edges;

    vector<list<int>> adjList(nodes);
    for(int i = 0; i < edges; i++){
        int u, v;
        cout << "Edge " << i + 1 << ": ";
        cin >> u >> v;


         if (u >= 0 && u < nodes && v >= 0 && v < nodes) {
            updateAdjacencyList(adjList, u, v);
        } else {
            cout << "Invalid edge: (" << u << ", " << v << "). Please try again!" << endl;
            i--; 
        }
    }

    
    cout << "\nFinal Adjacency List:" << endl;
    for (int i = 0; i < adjList.size(); i++) {
        cout << i << ": ";
        for (int value : adjList[i]) {
            cout << value << " ";
        }
        cout << endl;
    }

     cout << "Adjacency List generation complete. Thank you!" << endl;
    return 0;
}   



// Graph->travarsal;
// 1.DFS.


void Dfs(int start,vector<list<int>>&adjlist,vector<int>&visited,vector<int>&dfsTraversal){
    dfsTraversal.push_back(start);
    visited[start] = true;
    for(int neighbours: adjlist[start]){
        if(!visited[neighbours]){
            Dfs(neighbours,adjlist,visited,dfsTraversal);
        }
    }
}


// 2.BFS
void Bfs(int start,vector<list<int>>&adjlist){
    int n = adjlist.size();
    vector<int>visited(n, 0);
    queue<int>q;
    q.push(start);
    visited[start] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";
        visited[node] = 1;
        for(auto it: adjlist[node]){
            if(!visited[it]){
                q.push(it);
                visited[it] = 1;
            }
        }
    }
}
void updateAdjacencyList(vector<list<int>>&adjList, int v, int u){
    adjList[v].push_back(u);
    adjList[u].push_back(v);
}
int main(){
    int nodes, edges;
    cout << "Welcome to the Adjacency List Generator!" << endl;
    cout << "Enter the number of nodes and edges: ";
    cin >> nodes >> edges;
    vector<list<int>> adjList(nodes);
    for(int i = 0; i < edges; i++){
        int u,v;
        cin >> u >> v;
        if(u >= 0 && u < nodes && v >= 0 && v < nodes){
            updateAdjacencyList(adjList, u, v);
        }else{
            cout << "Invalid edge: (" << u << ", " << v << "). Please try again!" << endl;
            i--; 
        }
    }
    vector<int> visited(nodes,0);

    cout << "dfs travarsal is this: " << endl;
    vector<int>dfsTraversal;
    Dfs(0,adjList,visited,dfsTraversal);
    for(int i = 0; i < dfsTraversal.size(); i++){
        cout << dfsTraversal[i] << " ";
    }

    cout << "\n" << "bfs travarsal is this:"<< endl;
    Bfs(0,adjList);
}
