
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h> 
#include <limits.h> 
#include <algorithm>
#include <stack>
 
 
using namespace std;
bool dagDetect1(int arrSize, int numEdge, int* arr){
    //Dag detection
    bool visited[arrSize];
    for(int i = 0; i < arrSize; i++)
    {
        visited[i] = false;
    }
    int x=1;
    bool dag=true;
    for(int a=0;a<numEdge;a++){
        if(visited[arr[x]]==false){
            visited[arr[x]]=true;
        }
        else{
            dag=false;
        }
        x=x+2;
    }
    cout<<endl;
    if(dag==true){
        cout<<"this is a DAG"<<endl;
        return false;
    }
    else{
        cout<<"this isn't a DAG"<<endl;
        return true;
    }
}
int** create2DArray(int numVert,int numEdge, int* arr){
    int ** matrix = new int*[numVert];
    for(int a=0;a<numVert;a++){
         matrix[a] = new int[numVert];
    }
    for(int i = 0; i < numVert; ++i){
        for(int j = 0; j < numVert; ++j){
            matrix[i][j] = 0;
        }
    }
    int x=0;
    for(int a=0;a<numEdge;a++){
        matrix[arr[x]][arr[x+1]]+=1;
        x=x+2;
    }
    return matrix;
}

int* DFS(int** matrix, int* poppingOff,int startingNum,int numVert){
   
    bool visited[numVert];
    for(int i = 0; i < numVert; i++)
    {
        visited[i] = false;
    }
    stack <int> popOrder;
    popOrder.push(startingNum);
    visited[startingNum]=1;
    for(int x=startingNum;x<numVert;x++){
        for(int y=0;y<numVert;y++){
            if(matrix[x][y]==1&&visited[y]==false){
                visited[x]=true;
                popOrder.push(y);
            }
        }
        
    }
    cout<<"Popping-off order: ";
    while(!popOrder.empty())
    {
    cout<<popOrder.top()<< " ";
    popOrder.pop();
    }
    cout<<endl;
    
}

int main() {
    string fileName="t1.txt";
    //opening file and setting the first index to the array size
    cout<<"Please input file name: ";
    cin>>fileName;
    ifstream file(fileName.c_str());
    int numEdge;
    int numVert;
    
    file>>numVert;
    file>>numEdge;
    int arrSize=numEdge*2;
    int * arr;
    arr = new int[numEdge*2];
    int** matrix;
    int i=0;
    //reading the file after the first index and assigning it to the array
     while(!file.eof())
    {
        file >> arr[i];
        i++;
    }
    bool dagGraph=0;
    if(numEdge<5){
        dagGraph=dagDetect1(arrSize,numEdge,arr);
    }
    else{
        //write better dagDetect
    }
    if(dagGraph==0){
        matrix=create2DArray(numVert,numEdge,arr);
        i=0;
        int value;
        int startingSum=0;
        int* poppingOff= new int[numVert];
        int startingNum;
        for(int a=0;a<numVert;a++){
            for(int z=0;z<numVert;z++){
                startingSum+=matrix[a][z];
                value=a;
            }
            
            if(startingSum==0){
                startingNum=value;
                i++;
            }
            startingSum=0;
        }
        cout<<"Start node(s): "<< startingSum;
        cout<<endl;
        DFS(matrix,poppingOff,startingNum,numVert);
    }
}