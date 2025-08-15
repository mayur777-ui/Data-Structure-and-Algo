// !dijkstra algo
// ?why we should use this algo to find shortest distance
// ans=>To find the shortest distance from a source node to all other nodes in a weighted graph.
#include<bits/stdc++.h>
using namespace std;

vector<int>dijkstra(int V,vector<vector<pair<int,int>>>&adj, int S){
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>>pq; 
    vector<int>dist(V,1e9);
    dist[S] = 0;
    pq.push({0,S});
    
    while(!pq.empty()){
        auto [d, node] = pq.top();
        pq.pop();
        if(d > dist[node]) continue;
        for(auto it : adj[node]){
            int itnode = it.first;
            int itweight = it.second;
            if(itweight + d < dist[itnode]){
                dist[itnode] = itweight + d;
                pq.push({itweight + d, itnode});
            }
        }
    }
    return dist;
}

int main() {
    int V = 5;
    int S = 0;
        vector<vector<pair<int,int>>> adj(V);

    adj[0].push_back({1, 4});
    adj[0].push_back({2, 1});
    adj[2].push_back({1, 2});
    adj[1].push_back({3, 1});
    adj[2].push_back({3, 5});
    adj[3].push_back({4, 3});


    vector<int> shortestDist = dijkstra(V, adj, S);

    for(int i = 0; i < V; i++)
        cout << "Distance to node " << i << " = " << shortestDist[i] << endl;

    return 0;
}



// !Bellman-Ford algo(it's work for negative weight graph)

vector<int>bellman_ford(int V,  vector<vector<int>>&edges, int S)
{
    vector<int>dist(V, 1e9);
    dist[S] = 0;
    for(int i = 0;i < V - 1; i++){
        for(auto it: edges){
            int u = it[0];
int v = it[1];
int w = it[2];
            if(dist[u] != 1e9 && dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            } 
        }
    }

    for(auto it: edges){
       int u = it[0];
int v = it[1];
int w = it[2];
        if(dist[u] != 1e9 && dist[u] + w < dist[v]){
            return {-1};
        } 
    }

    return dist;
}

int main() {

	int V = 6;
	vector<vector<int>> edges(7, vector<int>(3));
	edges[0] = {3, 2, 6};
	edges[1] = {5, 3, 1};
	edges[2] = {0, 1, 5};
	edges[3] = {1, 5, -3};
	edges[4] = {1, 2, -2};
	edges[5] = {3, 4, -2};
	edges[6] = {2, 4, 3};

	int S = 0;
	vector<int> dist = bellman_ford(V, edges, S);
	for (auto d : dist) {
		cout << d << " ";
	}
	cout << endl;

	return 0;
}

