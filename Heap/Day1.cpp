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
        while(index > 0){
            int parent = (index - 1)/2;
            if(heap[index] > heap[parent]){
                swap(heap[index],heap[parent]);
                index = parent;
            }else{
                break;
            }
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