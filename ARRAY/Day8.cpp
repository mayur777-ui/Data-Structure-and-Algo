#include<bits/stdc++.h>
using namespace std;




// 	Find the row with maximum number of 1's

// Brute force
int rowWithMax1s(vector<vector<int>>mat, int n,int m){
    int max_ones = 0;
    int index = -1;
    for(int i = 0; i < n ;i++){
        int countones = 0;
        for(int j = 0; j < m; j++)
        {
            if(mat[i][j] == 1)
            countones++;
        }

        if(countones > max_ones){
            max_ones = countones;
            index = i;
        }
    }  
    return index;     
}



// Optimal approach
int lower_bound(vector<int> mat, int m, int key){
    int low = 0;
    int high = m - 1;
    int ans = INT_MAX;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(mat[mid] == key){
            ans = min(ans,mid);
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}

int rowWithMax1s(vector<vector<int>>mat, int n,int m){
        int max_ones = 0;
    int index = -1;
    for(int i = 0;i < n;i++){
        int countones = m - lower_bound(mat[i],m,1); //finding lower bound of one so that m - lower_bound  =  countone in that particular row
        if(countones>max_ones){
            max_ones = countones;
            index = i;
        }
    }
    return index;
}



int main()
{
    vector<vector<int>> matrix = {{0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
    int n = 3, m = 3;
    cout << "The row with maximum no. of 1's is: " <<
         rowWithMax1s(matrix, n, m) << '\n';
}






// Search in a sorted 2D matrix


// Brute force
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(), 
    m =(n > 0)?matrix[0].size():0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == target)
                return true;
        }
    }
    return false;
}

// Optimal approach 1.

bool searchInrow(vector<int> mat, int m,int key){
    int low = 0;
    int high = m - 1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(mat[mid] == key){
            return true;
        }else if(mat[mid] < key){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return false;
}


// Optimal approach 2.

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    int low = 0;
    int high = n * m - 1;
    while(low <= high){
        int mid = low + (high - low)/2;
        int row = mid/m;
        int col = mid%m;
        if(matrix[row][col] == target){
            return true;
        }else if(matrix[row][col] < target) {
            low = mid+1;
        }
        else {
            high = mid -1;
        }
    }
    return false;
}
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n =  matrix.size();
    int m =  (n > 0)?matrix[0].size() : 0; 
    for(int i = 0; i < n;i++){
        if(searchInrow(matrix[i],m,target)){
            return true;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> mat = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    cout << searchMatrix(mat, 3);
}


