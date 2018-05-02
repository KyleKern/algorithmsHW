// A C++ program to demonstrate common Binary Heap Operations
#include<iostream>
#include<climits>
using namespace std;
 
// Prototype of a utility function to swap two integers
void swap(int *x, int *y);
 
// A class for Min Heap
class MinHeap
{
    int *harr; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap
public:
    // Constructor
    MinHeap(int capacity);
 
    // to heapify a subtree with root at given index
    void MinHeapify(int );
 
    int parent(int i) { return (i-1)/2; }
 
    // to get index of left child of node at index i
    int left(int i) { return (2*i + 1); }
 
    // to get index of right child of node at index i
    int right(int i) { return (2*i + 2); }
 
    // to extract the root which is the minimum element
    int extractMin();
 
    // Decreases key value of key at index i to new_val
    void decreaseKey(int i, int new_val);
 
    // Returns the minimum key (key at root) from min heap
    int getMin() { return harr[0]; }
 
    // Deletes a key stored at index i
    void deleteKey(int i);
 
    // Inserts a new key 'k'
    void insertKey(int k);
    
    //print heap
    void printHeap();
    
    int findMax();
    
};
 
// Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}
 
// Inserts a new key 'k'
void MinHeap::insertKey(int k)
{
    if (heap_size == capacity)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }
 
    // First insert the new key at the end
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;
 
    // Fix the min heap property if it is violated
    while (i != 0 && harr[parent(i)] > harr[i])
    {
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}
 
// Decreases value of key at index 'i' to new_val.  It is assumed that
// new_val is smaller than harr[i].
void MinHeap::decreaseKey(int i, int new_val)
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i])
    {
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}
 
// Method to remove minimum element (or root) from min heap
int MinHeap::extractMin()
{
    if (heap_size <= 0)
        return INT_MAX;
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }
 
    // Store the minimum value, and remove it from heap
    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    MinHeapify(0);
 
    return root;
}
int MinHeap::findMax(){
    int max=0;
    for(int x=0;x<heap_size;x++){
        if(harr[x]>max){
            max=harr[x];
        }
    }
    return max;
}
 
// This function deletes key at index i. It first reduced value to minus
// infinite, then calls extractMin()
void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void MinHeap::printHeap(){
    for(int x=heap_size-1;x>=0;x--){
        cout<<harr[x]<<" ";
    }
    cout<<endl;
}
int heapCheck(int arr[], int i, int n){
   if (i > (n - 2)/2){
       return 1;
   }
   if (arr[i] >= arr[2*i + 1]  &&  arr[i] >= arr[2*i + 2] &&
       heapCheck(arr, 2*i + 1, n) && heapCheck(arr, 2*i + 2, n)){
       return 1;
       }
   return 0;
}
int main()
{
    int arrSize;
    int input;
    int* arr=new int[arrSize];
    cout<<"Input Size: ";
    cin>>arrSize;
    MinHeap h(arrSize*2);
    cout<<"Enter numbers: ";
    for(int x=0;x<arrSize;x++){
        arr[x]=input;
        cin>>input;
        h.insertKey(input);
    }
    int n=sizeof(arr)/sizeof(arr[0]);
    int check=heapCheck(arr,0,n);
    if(check==1){
        cout<<"is a heap"<<endl;
        //heapSort(arr,n);

    } else {
        cout<<"is not a heap"<<endl;
        cout<<"Heap constructed: ";
        h.printHeap();
    }
    int operation;
    int newInput;
     int cont=0;
    while(cont!=1){
        cout<<"Select an operation: "<<endl;
        cout<<"    1: Insert a number"<<endl;
        cout<<"    2: Delete the max"<<endl;
        cout<<"    3: Heapsort & Quit"<<endl;
        cin>>operation;
        if(operation==1){
            cout<<"Enter a number: ";
            cin>>newInput;
            h.insertKey(newInput);
            cout<<"Updated heap:";
            for(int x=0;x<arrSize;x++){
                h.MinHeapify(x);
            }
            h.printHeap();
            cout<<endl;
        }else if(operation==2){
            //call delete function
            
        }else if(operation==3){
            //h.MinHeapify();
            cout<<"Heapsort: ";
            h.printHeap();
            cout<<endl;
            cout<<"Bye!"<<endl;
            cont=1;
        }
    }
    return 0;
}