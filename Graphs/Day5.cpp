#include <bits/stdc++.h>
using namespace std;
// Find distance from zero
vector<vector<int>>updateMat(vector<vector<int>>&mat){
    int n = mat.size();
    int m = mat[0].size();
    queue<pair<int,int>> q;
    vector<vector<int>>dist(n,vector<int>(m,INT_MAX));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
        {
            if(mat[i][j] == 0){
                q.push({i,j});
                dist[i][j] = 0;
            }
        }
    }

    vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();
        for(auto [dx,dy]: directions){
            int nx = x + dx;
            int ny = y + dy;
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                if(dist[nx][ny] > dist[x][y] + 1){
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx,ny});
                }
            }
        }
    }
    return dist;
}

int main(){
    vector<vector<int>> mat = {{0,0,0},{0,1,0},{1,1,1}};
    vector<vector<int>> res = updateMat(mat);
    for(auto it: res){
        for(auto it1: it){
            cout << it1 << " ";
        }
        cout << endl;
    }
}

// Surrounded Regions (Leetcode-130) - BFS Solution
#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<char>>&board) {
    int n = board.size();
    if (n == 0) return;
    int m = board[0].size();
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j : {0, m - 1}) {
            if (board[i][j] == 'O') {
                q.push({i, j});
                board[i][j] = '#';
            }
        }
    }
    for (int j = 0; j < m; j++) {
        for (int i : {0, n - 1}) {
            if (board[i][j] == 'O') {
                q.push({i, j});
                board[i][j] = '#';
            }
        }
    }

    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (auto [dx, dy] : directions) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] == 'O') { // ✅ Corrected condition
                q.push({nx, ny});
                board[nx][ny] = '#';
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'O') board[i][j] = 'X';
            if (board[i][j] == '#') board[i][j] = 'O';
        }
    }
}

int main() {
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'X', 'X'}
    };
    solve(board);
    int n = board.size();
    int m = board[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
