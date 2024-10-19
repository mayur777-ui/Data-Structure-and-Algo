#include<iostream>
#include<climits>
using namespace std;
 
// find the sencod smallest
 
int main(){
    int n;
    cin >> n;  
    int a[n];
    
    for(int i = 0; i < n; i++){
        cin >> a[i];  
    }

    int small = INT_MAX;
    int s_small = INT_MAX;  

    for(int i = 0; i < n; i++){
        if(a[i] < small){
            s_small = small;
            small = a[i];
        }
        else if(a[i] < s_small && a[i] != small){
            s_small = a[i];
        }
    }

    cout << "Smallest element: " << small << endl;
    cout << "Second smallest element: " << s_small << endl;

    return 0;
}



// find second largest element

#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int large = INT_MIN;
    int L_large =  INT_MIN;
    for(int i = 0; i < n; i++){
        if(a[i] > large){
            L_large = large;
            large = a[i];
        }else if(a[i] > L_large && a[i] != large){
            L_large = a[i];
        }
    }

    cout << "Largest element: "<< large << "\n";
    cout << "Second Largest element: "<< L_large;
}



// FIND Arry is SOrted or roted
#include <iostream>
#include <vector>
using namespace std;

bool checkSortedAndRotated(vector<int>& nums) {
    int count = 0;
    int n = nums.size();
    
    for (int i = 0; i < n; i++) {
        if (nums[i] > nums[(i + 1) % n]) {
            count++;
        }
        // If there is more than one such instance, it can't be sorted and rotated
        if (count > 1) return false;
    }
    return true;
}

int main() {
    vector<int> nums = {3, 4, 5, 1, 2};
    bool result = checkSortedAndRotated(nums);
//     cout << (result ? "true" : "false") << endl;
//     return 0;
// }





// Left Rotate an arr by one place
#include <iostream>
using namespace std; 
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int b[n] = {0};
    for(int i = 0; i < n; i++){
        b[i] = a[(i + 1)%n];
    }

    for(int i = 0; i < n;i++){
        cout << b[i] << " ";
    }
};



// Revrsal algo an arr

 

void Reverse(int arr[],int start,int end){
    int i = start;
    int j = end;
    while(i <= j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int k = 3;
    Reverse(a,0,n - 1);
    Reverse(a,0, k - 1);
    Reverse(a, k, n - 1);
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}


// Traversal through an circular arr;
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v {61,4,2,4,6,33,56,2};
    int n = v.size();
    for (int i = 0; i < 2 * n; i++) { 
        cout << v[i%n] << " ";
    }
}

