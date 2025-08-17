#include<bits/stdc++.h>
using namespace std;

// Prim's Algorithm
int spanningTree(int V, vector<vector<pair<int, int>>>&adj){
     priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>>pq; 
     int sum = 0;
     vector<int>vis(V,0);
     pq.push({0,0});
     while(!pq.empty()){
        auto [wt, node] = pq.top();
        pq.pop();
        if(vis[node]) continue;
        vis[node] = 1;
        sum += wt;
        for(auto it: adj[node]){
            auto [itnode,itweight] = it;
            if(!vis[itnode]){
                pq.push({itweight, itnode});
            }
        }
     }

     return sum;
}

int main() {
    int V = 5;
	vector<vector<pair<int,int>>> adj = {
        { {1,2}, {2,1} },     
        { {0,2}, {2,1} },       
        { {0,1}, {1,1}, {3,2}, {4,2} },
        { {2,2}, {4,1} },       
        { {3,1}, {2,2} }        
    };
	int sum = spanningTree(V, adj);
	cout << "The sum of all the edge weights: " << sum << endl;

	return 0;
}




// Disjoin Set Union(Dsu)

// Broute Force of Dsu

class DisjointSet{
    vector<int>parent;
    public:
    DisjointSet(int V){
        parent.resize(V+1);
        for(int i = 0; i < V; i++) parent[i] = i;
    }
    public:
    int findUParent(int node){
        if(node == parent[node])return node;
        return findUParent(parent[node]);
    }
    void unionBroute(int u, int v){
        int pu = findUParent(u);
        int pv = findUParent(v);

        if(pu != pv){
            parent[u] = v;
        }
    }
};


int main(){
    DisjointSet ds(7);
    ds.unionBroute(1, 2);
    ds.unionBroute(2, 3);
    ds.unionBroute(4, 5);
    ds.unionBroute(6, 7);
    ds.unionBroute(5, 6);
    // if 3 and 7 same or not
    if (ds.findUParent(3) == ds.findUParent(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionBroute(3, 7);

    if (ds.findUParent(3) == ds.findUParent(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    return 0;
}


//Optimized version(By RANK)
class DisjointSetRank{
    vector<int>parent;
    vector<int> rank;
    public:
    DisjointSetRank(int V){
        parent.resize(V+1);
        rank.resize(V+ 1, 0);
        for(int i = 0; i < V; i++) parent[i] = i;
    }
    public:
    int findUParent(int node){
        if(node == parent[node])return node;
        return parent[node] =  findUParent(parent[node]);
    }
    void unionRank(int u, int v){
        int pu = findUParent(u);
        int pv = findUParent(v);
            if (pu == pv) return;

        if(rank[pu] > rank[pv]){
            parent[u] = v;
        }else if(rank[pv] > rank[pu]){
            parent[v] = u;
        }else{
            parent[u] = v;
            rank[u]++;
        }
    }
};



int main(){
     DisjointSetRank ds(7);
    ds.unionRank(1, 2);
    ds.unionRank(2, 3);
    ds.unionRank(4, 5);
    ds.unionRank(6, 7);
    ds.unionRank(5, 6);
// if 3 and 7 same or not
    if (ds.findUParent(3) == ds.findUParent(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionRank(3, 7);

    if (ds.findUParent(3) == ds.findUParent(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    return 0;
}





//Optimized version(By size)
class DisjointSetSize{
    vector<int>parent;
    vector<int>size;
    public:
    DisjointSetSize(int V){
        parent.resize(V + 1);
        size.resize(V + 1, 0);
        for(int i = 0; i < V; i++) parent[i] = i;
    }
    public:
    int findUParent(int node){
        if(node == parent[node])return node;
        return parent[node] =  findUParent(parent[node]);
    }
    void unionSize(int u, int v){
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



int main(){
     DisjointSetSize ds(7);
    ds.unionSize(1, 2);
    ds.unionSize(2, 3);
    ds.unionSize(4, 5);
    ds.unionSize(6, 7);
    ds.unionSize(5, 6);
    // if 3 and 7 same or not
    if (ds.findUParent(3) == ds.findUParent(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionSize(3, 7);

    if (ds.findUParent(3) == ds.findUParent(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    return 0;
}