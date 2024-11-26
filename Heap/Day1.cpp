// // Implementation of heap
#include <iostream>
using namespace std;

class MaxHeap {
    int* heap;
    int size;
    int total_size;

public:
    // Constructor
    MaxHeap(int n) {
        heap = new int[n];
        size = 0;
        total_size = n;
    }

    // Destructor
    ~MaxHeap() {
        delete[] heap;
    }

    // Insert element into the heap
    void insert(int value) {
        if (size >= total_size) {
            cout << "Heap Overflow\n";
            return;
        }
        int index = size;
        heap[index] = value;
        size++;

        // Up-heapify
        int parent = (index - 1) / 2;
        while (index > 0 && heap[parent] < heap[index]) {
            swap(heap[parent], heap[index]);
            index = parent;
            parent = (index - 1) / 2; 
        }
    }

    // Heapify to restore max-heap property
    void heapify(int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && heap[largest] < heap[left]) {
            largest = left;
        }
        if (right < size && heap[largest] < heap[right]) {
            largest = right;
        }

        if (largest != i) {
            swap(heap[largest], heap[i]);
            heapify(largest);
        }
    }

    // Delete the root element
    void deletion() {
        if (size == 0) {
            cout << "Heap is empty\n";
            return;
        }
        heap[0] = heap[size - 1];
        size--;
        heapify(0);
    }

    // Print the heap
    void print() {
        for (int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    MaxHeap heap(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        heap.insert(value);
    }

    cout << "Heap elements: ";
    heap.print();

    cout << "After deletion of root: ";
    heap.deletion();
    heap.print();

    return 0;
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
    builtheap(arr,10);
    heapsort(arr,10);
    print(arr,10);
}

