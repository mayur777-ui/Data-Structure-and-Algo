#include <bits/stdc++.h>
using namespace std;

// 	Kruskal's Algorithm

class DisjointSet{
    vector<int>parent;
    vector<int>size;
    public:
    DisjointSet(int V){
        parent.resize(V + 1);
        size.resize(V + 1, 0);
        for(int i = 0; i < V; i++) parent[i] = i;
    }
    public:
    int findUParent(int node){
        if(node == parent[node])return node;
        return parent[node] =  findUParent(parent[node]);
    }
    void Dis_union(int u, int v){
        int pu = findUParent(u);
        int pv = findUParent(v);
        if(pu == pv) return;
        if(size[pu] > size[pv]){
            parent[u] = v;
        }else if(size[pv] > size[pu]){
            parent[v] = u;
        }else{
            parent[u] = v;
            size[u]++;
        }
    }
};


int KruskalMinSpenningTree(int V,vector<vector<pair<int, int>>>&adjList){
    vector<pair<int,pair<int, int>>>edges;
    for(int i = 0; i < V;i++){
        for(auto it: adjList[i]){
            int adjNode = it.first;
            int wt = it.second;
            int node = i;
            edges.push_back({wt, {node, adjNode}});
        }
    }

    sort(edges.begin(), edges.end());
    DisjointSet ds(V);
    int mstWt = 0;
    for(auto it: edges){
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;
        if(ds.findUParent(u) != ds.findUParent(v)){
            mstWt += wt;
            ds.Dis_union(u , v);
        }
    }
    return mstWt;
}

int main()
{
    int V = 5;
    vector<vector<pair<int, int>>> adjList = {
        {{1, 2}, {2, 1}},
        {{0, 2}, {2, 1}},
        {{0, 1}, {1, 1}, {3, 2}, {4, 2}},
        {{2, 2}, {4, 1}},
        {{3, 1}, {2, 2}}
    };

    int mst = KruskalMinSpenningTree(V, adjList);
    cout << mst;
}