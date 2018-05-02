/*
 * Title: HW1.cpp
 * Abstract: This program finds and displays the minimum distance between two numbers
 * Author: Kyle Kern
 * ID: 1313
 * Date: 01/26/2018 
 */

#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h> 
#include <limits.h> 
#include <algorithm>

using namespace std;

int main() {
    string fileName="t1.txt";
    //opening file and setting the first index to the array size
    cout<<"Please input file name: ";
    cin>>fileName;
    ifstream file(fileName.c_str());
    
    int arrSize;
    file>>arrSize;
    int * arr;
    arr = new int[arrSize];
    int i=1;
    int x, y;
    int check=1;
    //reading the file after the first index and assigning it to the array
     while(!file.eof())
    {
        file >> arr[i];
        i++;
    }
    //searching array for minimum distance between two index's values
    int n= sizeof(arr);
    
    int smallest_dis=99999;

     for (int i = 0; i < arrSize+1; i++){
         for (int j = i+1; j < arrSize+1; j++){
                if(arr[i]!=arr[j]){ 
                     if(smallest_dis > abs(arr[i]-arr[j])){
                            smallest_dis = abs(arr[i]-arr[j]);
                          
                     }
                }
            }
        }
 
   
    cout<<"minimum distance: " << smallest_dis << endl;
       // Search for a pair
  for (int i = 1; i < arrSize+1; i++){
         for (int j = i+1; j < arrSize+1; j++){
                if(arr[i]!=arr[j]){ 
                     if(smallest_dis == abs(arr[i]-arr[j])){
                         cout<< "Two numbers for minimum distance: "<< arr[i]<< " "<< arr[j]<< endl;
                     }
                }
            }
        }
    

 delete[] arr;
}
