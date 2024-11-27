#include<iostream>
#include<bits/stdc++.h>
using namespace std;




// //Shortest Path in UG with unit weights
vector<int>shortestPath(vector<vector<int>>&edges,int N,int M, int src){
    vector<int>adjList[N];
    for(auto it: edges){
        adjList[it[0]].push_back(it[1]);
        adjList[it[1]].push_back(it[0]);
    }

    vector<int> dist(N, INT_MAX);
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it:adjList[node]){
            if(dist[node] + 1 < dist[it]){
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
    }
    vector<int> ans(N, -1);
    for(int i = 0;i<N;i++) {
        if(dist[i] != INT_MAX){
            ans[i] = dist[i]; 
        }
    }

    return ans;
}

int main(){
    int N=9, M=10;
    vector<vector<int>> edges= {{0,1},{0,3},{3,4},{4,5},{5,6},{1,2},{2,6},{6,7},{7,8},{6,8}};

    vector<int> ans = shortestPath(edges,N,M,0);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}




//Shortest Path in UG with unit weights with given destination
int shortestPath(vector<vector<int>>&edges,int N,int M, int src,int dis){
    vector<int> adjList[N];
    for(auto it: edges){
        adjList[it[0]].push_back(it[1]);
        adjList[it[1]].push_back(it[0]);
    }   
    vector<int>dist(N, INT_MAX);
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it:adjList[node]){
            if(dist[node] + 1 < dist[it]){
                dist[it] = dist[node] + 1;
                q.push(it);
                if(it == dis) return dist[it];
            }
        }
    }
    return -1;
}


int main(){
    int N=9, M=10;
    vector<vector<int>> edges = {{0,1},{0,3},{3,4},{4,5},{5,6},{1,2},{2,6},{6,7},{7,8},{6,8}};
    int dist,source;
    cout<< "enter source and destination to find minimum distance: ";
    cin >> source >> dist;
    int result = shortestPath(edges, N, M, source, dist);
    if(result != -1) {
        cout << "Shortest distance from " << source << " to " << dist << " is: " << result << endl;
    } else {
        cout << "Destination " <<  dist << " is unreachable from source " <<source<< endl;
    }

}
