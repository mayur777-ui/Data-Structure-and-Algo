// connectedComponents
#include <bits/stdc++.h>
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

// Shortest Path in UG with unit weights

vector<int> shortestPath(vector<vector<int>> &adj, int src)
{
    int n = adj.size();
    vector<int> dist(n, 1e9);
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if (dist[node] + 1 < dist[it])
            {
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
    }

    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (dist[i] != 1e9)
        {
            ans[i] = dist[i];
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>>adj = {{3}, {3}, {}, { 0, 1 } };
    int src = 3;
    vector<int> ans = shortestPath(adj,src);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}





// Shortest Path in a Directed Acyclic Graph (DAG)

void topoDfs(int i, vector<int>&vis, vector<vector<pair<int,int>>>&adj,stack<int>&st){
    vis[i] = 1;
    for(auto it: adj[i]){
        if(!vis[it.first]){
            topoDfs(it.first, vis,adj,st);
        }
    }
    st.push(i);
}


vector<int>shortestPath(vector<vector<pair<int,int>>>&adj, int src){
    int n = adj.size();
    vector<int> dist(n, 1e9);
    stack<int>st;
    vector<int>vis(n, 0);
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            topoDfs(i,vis,adj,st);
        }
    }
    dist[src] = 0;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(dist[node] != 1e9){
            for(auto it: adj[node]){
                int wt = it.second;
                if(dist[node] + wt < dist[it.first]){
                    dist[it.first] = dist[node]+ wt;
                }
            }
        }

 }
        for(int i = 0; i < n; i++){
            if(dist[i] == 1e9) dist[i] = -1;
        }

        return dist;
}


int main()
{
    vector<vector<pair<int, int>>> adj = {
    { {1, 2}, {4, 1} },      
    { {2, 3} },              
    { {3, 6} },            
    { },                     
    { {5, 4}, {2, 2} },      
    { {3, 1} }               
};

    vector<int>ans = shortestPath(adj, 0);

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }

}





// Word Ladder
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> st(wordList.begin(), wordList.end());
    queue<pair<string, int>> q;
    q.push({beginWord, 1});

    while(!q.empty()){
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();
        if(word == endWord){
            return steps;
        }
        for(int i = 0; i < word.size(); i++){
            char original = word[i];
           for (char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                if(st.find(word) != st.end()){
                    st.erase(word);
                    q.push({word, steps + 1});
                }
            }
            word[i] = original;
        }
    }
    return 0;
}

int main(){
    string beginWord = "hit", endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    cout << ladderLength(beginWord,endWord, wordList);
}
