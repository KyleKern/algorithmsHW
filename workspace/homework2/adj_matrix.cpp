/*
 * Title: adj_matrix.cpp
 * Abstract: program creates adjancy matrix after reading number of vertices, edges, and where the edges vertices are
 * only takes in directed graph
 * Author: Kyle Kern
 * ID: 1313
 * Date: 02/04/2018 
 */

#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h> 


using namespace std;

int main() {
    string fileName="t1.txt";
    //opening file and setting the first index to the array size
    cout<<"Please input file name: ";
    cin>>fileName;
    ifstream file(fileName.c_str());
    int numEdge;
    int arrSize;
    file>>arrSize;
    file>>numEdge;
    int * arr;
    if(numEdge>0){
    arr = new int[numEdge+(numEdge-1)];
    }
    else{
        arr = new int[3];
    }
    int i=0;
    while(i<arrSize){
        arr[i]=1;
        i++;
    }
    i=0;
    //reading the file after the first and second index and assigning it to the array
    
    while(!file.eof())
    {
        file>>arr[i];
        i++;
    }
    //creating 2d array for matrix
    int ** matrix = new int*[arrSize];
    for(int a=0;a<arrSize;a++){
         matrix[a] = new int[arrSize];
    }
    for(int i = 0; i < arrSize; ++i){
        for(int j = 0; j < arrSize; ++j){
            matrix[i][j] = 0;
        }
    }
    
    cout<<"Number of vertices: "<<arrSize<<endl;
    cout<<"Number of edges: "<<numEdge<<endl;

    int x=0;
    for(int a=0;a<numEdge;a++){
        matrix[arr[x]][arr[x+1]]+=1;
        x=x+2;
    }
    cout<<"Adjacency matrix:"<<endl;
    for(int a=0;a<numVert;a++){
        for(int b=0;b<numVert;b++){
            cout<<matrix[a][b]<<" ";
        }
        cout<<endl;
    }
    cout<<"Thank you!"<<endl;
}