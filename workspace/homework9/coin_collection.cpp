/*
 * Title: coin_collection.cpp
 * Abstract: program finds the best path through an array based on max value
 *           prints out the total max and the path the program takes
 * Author: Kyle Kern
 * ID: 1313
 * Date: 04/23/18
 */

#include <iostream>
#include <fstream>
#include <list>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

int **f = new int*[25];
int c[25][25];

int best;
int max(int x, int y){
    if(x>y){
        return x;
    }
    else{
        return y;
    }
}
int robotCoinCollection_bottomup(int n, int m) 
{
	// Initialize the base case for the table
	f[0][0] = c[0][0];
	for (int j = 1; j <= m; j++) {
		f[0][j] = f[0][j-1] + c[0][j];
	}
	// do the dynamic programming
	for (int i = 1; i <= n; i++) {
		f[i][0] = f[i-1][0] + c[i][0];		
		for (int j = 1; j <= m; j++) {
			f[i][j] = max(f[i-1][j],f[i][j-1]) + c[i][j];
		}
	}
	return f[n][m];
}
void backtrace(int n, int m){
    if(m<0||n<0){
        cout<<"(0,0)"<<endl;
        return;
    }
    //cout<<endl;
    cout<<"("<<n<<","<<m<<")->";
   if(n-1<0){
       if(m-1>0){
         backtrace(n,m-1);
       }
       else{
           cout<<"(0,0)"<<endl;
           return;
       }
   }
   else{
    if(f[n-1][m]>f[n][m-1]){
        backtrace(n-1,m);
    }
    else{
        backtrace(n,m-1);
    }
   }
}
int main(){
    string fileName;
    best=0;
    int rowSize, colSize;
    cout<<"Please enter filename: ";
    cin>>fileName;
    ifstream file(fileName.c_str());
    file>>rowSize;
    file>>colSize;
    for(int x=0;x<25;x++){
        f[x]=new int[25];
    }
    int** arr= new int*[colSize];
    for(int x=0;x<colSize;x++){
        arr[x]=new int[rowSize];
    }
    int i=0;
    int j=0;
    while(!file.eof()){
        file >> c[i][j];
        i++;
        if(i==colSize){
            i=0;
            j++;
        }
    }
    //coinCount(arr,rowSize,colSize);
   for(int y=0;y<rowSize;y++){
    for(int x=0;x<colSize;x++){
           if(c[x][y]==2){
               c[x][y]=-99;
           }
       }
   }
   int a=robotCoinCollection_bottomup(colSize-1,rowSize-1);
   if(a>=0){
   cout<<"Max coins: "<<a<<endl;
   backtrace(colSize-1,rowSize-1);
   }
   else{
       cout<<"Max coins: 0"<<endl;
       cout<<"No unblocked Path!"<<endl;
       
   }
   return 1;
    
}