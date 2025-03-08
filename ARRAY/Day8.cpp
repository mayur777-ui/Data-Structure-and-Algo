#include<bits/stdc++.h>
using namespace std;




// 	Find the row with maximum number of 1's

// Broute force
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
        }else if(mat[mid] > key){
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