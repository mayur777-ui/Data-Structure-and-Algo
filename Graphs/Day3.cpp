#include<bits/stdc++.h>
using namespace std;




// void dfs(int start,vector<list<int>>&adjL,vector<int>&visited){
//     visited[start] = 1;
//     for(auto neighbours: adjL[start]){
//         if(!visited[neighbours]){
//             dfs(neighbours,adjL,visited);
//         }
//     }
// }

// int numProvinces(vector<vector<int>> adj,int V){
//     vector<list<int>> adjL(V);
//     for(int i = 0; i < V; i++){
//         for(int j = 0; j < V;j++){
//             if(adj[i][j] == 1 && i != j){
//                 adjL[i].push_back(j);
//                 adjL[j].push_back(i);
//             }
//         }
//     }
//     vector<int> visited(V, 0);
//     int cnt = 0;
//     for(int i = 0; i < V; i++){
//         if(!visited[i]){
//             cnt++;
//             dfs(i, adjL, visited); 
//         }
//     }
//     return cnt;
// }

// int main(){
//     vector<vector<int>> adj
//     {
//         {1, 0, 1},
//         {0, 1, 0},
//         {1, 0, 1}
//     };

//     cout << numProvinces(adj,3);
// }



//Rotting Oranges



int orangesRotting(vector<vector<int>>grid){
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int,int>> q;
    int fresh = 0;
    for(int  i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 2){
                q.push({i,j});
            }else if(grid[i][j] == 1){
                fresh++;
            }
        }
    }

    vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
    int time = 0;
    while(!q.empty() && fresh > 0){
        int size = q.size();
        for(int i = 0; i < size; i++)
        {
            auto [x,y] = q.front();
            q.pop();
            for(auto[dx,dy] :directions){
                int nx = x + dx;
                int ny = y + dy;
                if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1){
                    grid[nx][ny] = 2;
                    q.push({nx,ny});
                    fresh--;
                }
            }
        }
        time++;
    }

    return fresh == 0 ? time: -1;
}

int main(){
    vector<vector<int>>grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };

    int t = orangesRotting(grid);
    cout << t;
}