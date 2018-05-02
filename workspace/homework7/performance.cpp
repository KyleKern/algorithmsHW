/*
 * Title: performance.cpp
 * Abstract: program creates an array and assigns it to 3 total arrays then tests 3 search arrays on the arrays
 * reused some old code to do the time from a game design program and array makers from old 238 programs
 * Author: Kyle Kern
 * ID: 1313
 * Date: 04/06/2018 
 */

#include <iostream>
#include <list>
#include <limits.h>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <ctime>
using namespace std;
void currentTime(){
    time_t tt;
    struct tm * ti;
    time (&tt);
    ti = localtime(&tt);
    cout << asctime(ti);
}
int* Ascending(int inputSize,int order){
    int* arr=new int[inputSize];
    for(int x=0;x<inputSize;x++){
        arr[x]=x+1;
    }
    return arr;
}
int* Descending(int inputSize,int order){
    int* arr=new int[inputSize];
    int value=inputSize;
    for(int x=0;x<inputSize;x++){
        arr[x]=value;
        value--;
    }
    return arr;
}
int* Random(int inputSize,int order){
    int* arr=new int[inputSize];
    srand (time(NULL));
    for(int x=0;x<inputSize;x++){
        
        arr[x]=rand()%inputSize+1;
    }
    return arr;
}
void swap(int* x, int* y){
    int temp =*x;
    *x= *y;
    *y=temp;
}
int selectionSort(int* arr,int inputSize){
    cout<<endl<<"====================================================="<<endl;
    cout<<"selection sort performance"<<endl;
    cout<<"Starting time: ";
    currentTime();
    time_t t;
    time_t e;
    t = clock();
    int min;
    for(int x=0;x<inputSize-1;x++){
        min=x;
        for(int y=x+1;y<inputSize;y++){
            if(arr[y]<arr[min]){
                min=y;
            }
        }
        swap(arr[min],arr[x]);
    }
    e=clock();
    cout<<"Ending time: ";
    currentTime();
    t = (clock() - t)/10000;
    cout<<"Elapsed time: "<<t<<" seconds";
    cout<<endl<<"====================================================="<<endl;
}

int insertionSort(int* arr,int inputSize){
    cout<<endl<<"====================================================="<<endl;
    cout<<"insertions sort performance"<<endl;
    cout<<"Starting time: ";
    currentTime();
    clock_t t;
    clock_t e;
    t = clock();
    int pivot;
    int y;
    for(int x=1;x<inputSize;x++){
        pivot=arr[x];
        y=x-1;
        while(y>=0 && arr[y]>pivot){
            arr[y+1]=arr[y];
            y=y-1;
        }
        arr[y+1]=pivot;
    }
    e=clock();
    cout<<"Ending time: ";
    currentTime();
    t = (clock() - t)/10000;
    cout<<"Elapsed time: "<<t<<" seconds";
    cout<<endl<<"====================================================="<<endl;
}
int partition(int* arr,int low,int high){
    int pivot = arr[high];
    int i=(low-1);
    for(int x=low;x<=high-1;x++){
        if(arr[x]<= pivot){
            i++;
            swap(arr[i],arr[x]);
        }
    }
    swap(arr[i+1],arr[high]);
    return(i+1);
}
int quickSortHelper(int* arr,int low,int inputSize){
    int high=inputSize-1;
    if(low<high){
        int split=partition(arr,low,high);
        quickSortHelper(arr,low,split-1);
        quickSortHelper(arr,split+1,high);
    }
}
int quickSort(int* arr,int low,int inputSize){
    cout<<endl<<"====================================================="<<endl;
    cout<<"quick sort performance"<<endl;
    cout<<"Starting time: ";
    currentTime();
    clock_t t;
    clock_t e;
    t = clock();
    quickSortHelper(arr,low,inputSize);
    e=clock();
    cout<<"Ending time: ";
    currentTime();
    t = (clock() - t)/10000;
    cout<<"Elapsed time: "<<t<<" seconds";
    cout<<endl<<"====================================================="<<endl;
}

int main(){
    ofstream myfile ("input.txt");
    int inputSize;
    int order;
    int* generatedData;
    int* generatedData2;
    int* generatedData3;
    cout<<"Enter input size: ";
    cin>>inputSize;
    cout<<"=========== Select Order of Input Numbers ==========="<<endl;
    cout<<"1. Ascending Order"<<endl;
    cout<<"2. Descending Order"<<endl;
    cout<<"3. Random Order"<<endl;
    cout<<"Choose order: ";
    cin>>order;
    if(order==1){
        cout<<endl<<"====================================================="<<endl;
        cout<<"Generating input data in ascending order . . . "<<endl<<"Done."<<endl;
        cout<<"====================================================="<<endl;
        generatedData=Ascending(inputSize,order);
        generatedData2=generatedData;
        generatedData3=generatedData;
    } else if(order==2){
        cout<<endl<<"====================================================="<<endl;
        cout<<"Generating input data in descending order . . . "<<endl<<"Done."<<endl;
        cout<<"====================================================="<<endl;
        generatedData=Descending(inputSize,order);
        generatedData2=generatedData;
        generatedData3=generatedData;
    } else if(order==3){
        cout<<endl<<"====================================================="<<endl;
        cout<<"Generating input data in random order . . . "<<endl<<"Done."<<endl;
        cout<<"====================================================="<<endl;
        generatedData=Random(inputSize,order);
        generatedData2=generatedData;
        generatedData3=generatedData;
    } else{
        cout<<"No order selected please try again!"<<endl;
        return -1;
    }
    myfile.close();
    selectionSort(generatedData,inputSize);
    insertionSort(generatedData2,inputSize);
    quickSort(generatedData3,0,inputSize);
     for(int x=0;x<inputSize;x++){
        cout<< generatedData2[x]<<" ";
    }
    
    return -1;
}