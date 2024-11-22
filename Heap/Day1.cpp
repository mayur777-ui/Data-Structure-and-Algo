// Implementation of heap
#include<bits/stdc++.h>
using namespace std;


class MaxHeap{
    int* heap;
    int size;
    int total_size;
    public:
    MaxHeap(int n){
        heap = new int[n];
        size = 0;
        total_size = n;
    }
    // Insert into the heap;
    void insert(int value){
        if(size >= total_size){
            cout << "Heap Overflow\n";
            return;
        }
        int index = size;
        heap[index] = value;
        size++;
        int parent = (index - 1)/2;
        while(index > 0 && heap[parent] < heap[index]){
            swap(heap[parent], heap[index]);
            index = parent;
        }

    } 
    void heapify(int i){
        int largest = i;
        int Left = 2 * i + 1;
        int right = 2 * i + 2;
        if(Left < size && heap[largest] < heap[Left]){
            largest = Left;
        }

        if(right < size && heap[largest] < heap[right]){
            largest = right;
        }

        if(largest != i){
            swap(heap[largest],heap[i]);
            heapify(largest);
        }
    }
    void deleteion(){
        if(size == 0){
            cout << "Heap is empty\n";
            return;
        }
        heap[0] = heap[size - 1];
        size--;
        int index = 0;
        heapify(index);


    }
    void print(){
        for(int i = 0; i < size; i++){
            cout <<heap[i] << " "; 
        }
        cout << endl;
    }


};

int main(){
    int n;
    cin >> n;
    MaxHeap heap(n);
    for(int i = 0; i < n; i++){
        int s;
        cin >> s;
        heap.insert(s);
    }
    heap.print();
    heap.deleteion();
    heap.print();
}


// By an given arr making an  heap
void heapify(int arr[], int i, int n){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != i){
        swap(arr[i],arr[largest]);
        heapify(arr, largest, n);
    }
}
void builtheap(int arr[],int n){
    for(int i = n/2 - 1; i >= 0; i--){
        heapify(arr,i,n);
    }
}

// heap sort

void heapsort(int arr[],int n){
    builtheap(arr,n);
    for(int i = n - 1; i >= 0; i--){
        swap(arr[0],arr[i]);
        heapify(arr,0,i);
    }
}

void print(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int arr[] = {10,3 ,8 ,9 ,5, 13 ,18 , 14 , 11 ,70};
    // builtheap(arr,10);
    heapsort(arr,10);
    print(arr,10);
}

