#include <bits/stdc++.h>
using namespace std;


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
