/*
 * Title: BFS.cpp
 * Abstract: program takes in the number of vertexes and adjacency matrix and does a breadth first search on it
 * Author: Kyle Kern
 * ID: 1313
 * Date: 03/07/2018 
 */

#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h> 
using namespace std;
int main() {
   string input;
    //opening file and setting the first index to the array size
    cout<<"Please input file name: ";
    cin>>input;
    int starter;
    cout<<"What vertex is first: ";
    cin>>starter;
    ifstream file(input.c_str());
    int numEdge;
    int arrSize;
    file>>arrSize;
    int * mark;
    mark=new int[arrSize];
    int * check;
    check=new int[arrSize];
    //std::queue<int> q;
    int * arr;
    if(arrSize>0){
        arr= new int[arrSize];
    }
    else{
        arr = new int[3];
    }
     // int i=0;
    //i=0;
    
    //reading the file after the first and second index and assigning it to the array
    int ** matrix = new int*[arrSize];
    for(int a=0;a<arrSize;a++){
         matrix[a] = new int[arrSize];
    }
    while(!file.eof()){
    for(int x=0;x<arrSize;x++){
        for(int y=0;y<arrSize;y++){
            file>>matrix[x][y];
            }
        }
    }
    
    for(int x=0;x<arrSize;x++){
        for(int y=0;y<arrSize;y++){
           cout<<matrix[x][y]<<" ";
            }
        cout<<endl;
    }
    for(int x=0;x<arrSize;x++){
        mark[x]=0;
        check[x]=0;
    }
    //q.push(0);
    int i=1;
    if(starter==0){
    mark[0]=0;
    for(int x=0;x<arrSize;x++){
        for(int y=0;y<arrSize;y++){
            if(matrix[x][y]==1){
                if(mark[y]==0&&y!=0){
                    mark[y]=i;
                    i++;
                    }
                }
            }
        }
    }
    else{
    mark[0]=starter;
    check[starter]=1;
    //array for above
    for(int x=starter;x>=0;x--){
        for(int y=0;y<arrSize;y++){
            if(matrix[x][y]==1){
                if(mark[i]==0&&check[y]==0){
                    check[y]=1;
                    mark[i]=y;
                    i++;
                }
            }
        }
    }
    for(int x=starter;x<arrSize;x++){
        for(int y=0;y<arrSize;y++){
            if(matrix[x][y]==1){
                if(mark[i]==0&&check[y]==0){
                    check[y]=1;
                    mark[i]=y;
                    i++;
                }
            }
        }
    }
      
    }   
    for(int x=0;x<arrSize;x++){
        if(x==arrSize-1){
            cout<<mark[x]<<endl;
        }
        else{
        cout<<mark[x]<<"->";
        }
    }
    
}