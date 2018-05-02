/* Title: heap.cpp
 * Author: Kyle Kern 
 * Date: 4/12/18
 * ID: 1313
 * Abstract: Program takes in the size of an array and the contents in the array. Then it sorts them into a heap
 *           Program has the ability to add and delete parts of the heap
*/

#include <iostream>
#include <list>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int smallest = i; // Initialize smalles as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    if (l < n && arr[l] < arr[smallest])
        smallest = l;
 
    if (r < n && arr[r] < arr[smallest])
        smallest = r;
 
    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
void printArray(int arr[], int n)
{
   for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
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
void addHeap(int arr[],int x,int n){
    arr[n]=x;
    int z=sizeof(arr)/sizeof(arr[0]);
    for(int y=0;y<n;y++){
    heapSort(arr,z);
    }
}
int findMin(int arr[],int n){
    int min=arr[0];
    int minIndex=0;
    for(int x=1;x<n;x++){
        if(arr[x]<min){
            minIndex=x;
            min=arr[x];
        }
    }
    return minIndex;
}
void deleteMax(int arr[],int n){
    int minIndex=findMin(arr,n);
    arr[0]=arr[minIndex];
    for(int x=minIndex;x<n;x++){
        arr[x]=arr[x+1];
    }
}

int main(){
    int arrSize;
    int newInput;
    int heapSize=0;
    int operation;
    cout<<"Input size: ";
    cin>>arrSize;
    int *arr= new int[arrSize*2];
    cout<<"Enter numbers: ";
    for(int x=0;x<arrSize;x++){
        cin>>arr[x];
        heapSize++;
    }
    int n=sizeof(arr)/sizeof(arr[0]);
    int check=heapCheck(arr,0,n);
    if(check==1){
        cout<<"is a heap"<<endl;
        printArray(arr,arrSize);
    } else {
        cout<<"is not a heap"<<endl;
        heapSort(arr,arrSize);
        cout<<"Heap constructed: ";
        printArray(arr,arrSize);
    }
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
            int n=sizeof(arr)/sizeof(arr[0]);
            addHeap(arr,newInput,arrSize);
            arrSize++;
            heapSort(arr,arrSize);
            printArray(arr,arrSize);
        }else if(operation==2){
            deleteMax(arr,arrSize);
            heapSort(arr,arrSize);
            arrSize--;
            printArray(arr,arrSize);
        }else if(operation==3){
            int n=sizeof(arr)/sizeof(arr[0]);
            heapSort(arr,n);
            printArray(arr,arrSize);
            cout<<"Bye!"<<endl;
            cont=1;
        }
    }
    
    return 0;
}