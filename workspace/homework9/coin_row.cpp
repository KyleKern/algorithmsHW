/*
 * Title: coin_row.cpp
 * Abstract: program finds what order to take on a coin row and prints out the max and route it takes
 * Author: Kyle Kern
 * ID: 1313
 * Date: 04/23/2018 
 */

#include <iostream>
#include <list>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

int max(int x, int y){
    if(x>y){
        return x;
    }
    else{
        return y;
    }
}
int backtrace(int* arr[], int numCoins){
    cout<<"Best set: ";
    int best=0;
    bool notbest=0;
    for(int x=numCoins+1;x>0;x--){
        if(arr[x][2]>arr[x-1][2]){
            if(notbest==0){
                best=arr[x][2];
                notbest=1;
            }
            cout<<arr[x][0]<<" ";
            x--;
        }
    }
    cout<<endl;
    return best;
}
int findMax(int* arr[],int numCoins){
    arr[1][2]=arr[1][1];
    int c;
    for(int x=1;x<numCoins;x++){
        c=arr[x][1];
        if(x-2<0){
            arr[x][2]=max(arr[x-1][1],c);
        }
        else{
        arr[x][2]=max(arr[x-1][2],(c+arr[x-2][2]));
        }
    }
}
int main(){
    int numCoins;
    cout<<"Number of coin(s): ";
    cin>>numCoins;
    int** arr= new int*[numCoins+2];
    for(int x=0;x<numCoins+2;x++){
        arr[x]=new int[3];
    }
    cout<<"Value(s): ";
    arr[0][0]=0;
    arr[0][1]=0;
    arr[0][2]=0;
    for(int x=1; x<numCoins+1;x++){
        arr[x][0]=x;
        arr[x][2]=0;
        cin>>arr[x][1];
    }
    findMax(arr,numCoins+2);
    for(int y=0;y<3;y++){
        for(int x=0;x<numCoins+1;x++){
            cout<<arr[x][y]<<" ";
        }
        cout<<endl;
    }
    int best=backtrace(arr,numCoins);
    
    cout<<"Max value: "<<best;
    return 1;
}