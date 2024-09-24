//MERGE SORT 
#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>&a,int low,int mid,int high){
    int left = low;
    int right = mid + 1;
    vector<int> temp;
    while(left <= mid && right <= high){
        if(a[left] <=  a[right]){
            temp.push_back(a[left]);
            left++;
        }else{
            temp.push_back(a[right]);
            right++;
        }
    }

    while(left <= mid){
        temp.push_back(a[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(a[right]);
        right++;
    }
    for(int i = low; i <= high; i++){
        a[i] = temp[i - low];
    }
}


void mergeSort(vector<int>&a,int low, int high){
    if(low >= high) return;
    int mid = (low + high) / 2;
    mergeSort(a,low,mid);
    mergeSort(a,mid+1,high);
    merge(a,low,mid,high);
}
int main() {
    int n;
    cin >> n;
    vector<int> a(n); 

   
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    
    mergeSort(a, 0, n - 1);

    
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}


// quick sort
#include<bits/stdc++.h>
using namespace std;
int partition(vector<int>&arr, int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i+1;
}

void qs(vector<int>&arr, int low, int high){
    if(low < high){
        int pivot = partition(arr,low,high);
        qs(arr,low,pivot - 1);
        qs(arr,pivot+1,high);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    qs(a, 0, n - 1);

    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }

}


#include<bits/stdc++.h>
using namespace std;

int rotetedNum(vector<int>& a,int low,int high){
    int ans = INT_MAX;
    int index = -1;
    while(low < high){
        int mid = low + (high - low)/2;
        // check for whole space;
        if(a[low] <= a[high]){
            if(a[low] < ans){
                ans = a[low];
                index = low;
            }
            break;
        }

        if(a[low] <= a[mid]){
            if(a[low] <= ans){
                ans = a[low];
                index = low;
            }
            low = mid + 1;
        }

        else{
            if(a[mid] < ans){
                ans = a[mid];
                index = mid;
            }
            high = mid - 1;
        }
    }
    return index;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    cout << rotetedNum(a, 0, n - 1);
}



// Selection sort
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n - 1; i++){
        int min = i;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
        
    }
    cout << "After selection sort: " << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}

 
insertion sort
int  main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >>arr[i];
    }
    for(int i = 0;i < n; i++){
        int j = i;
        while(j > 0 && arr[j - 1] > arr[j]){
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
        }
    }

    cout << "After selection sort: " << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}
