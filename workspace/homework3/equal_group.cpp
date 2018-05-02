/*
 * Title: equal_group.cpp
 * Abstract: Program takes in an array and sorts it, then sets the first two indexes to two new arrays, adds following indexes to the arrays
 * Author: Kyle Kern
 * ID: 1313
 * Date: 02/23/2018 
 */
#include <iostream>
#include <stdio.h>   
#include <math.h>
#include <stdlib.h>
#include <limits.h>
using namespace std;
int main() {
    cout<<"Number of input?: ";
    int input;
    cin>>input;
    int * arr;
    arr = new int[input];
    int num;
    int temp;
    int sum1, sum2;
    sum1=sum2=0;
    int * solution1;
    solution1 = new int[input];
    int * solution2;
    solution2 = new int[input];
    //take numbers and assign them to array
    cout<<"Enter "<<input<<" numbers: ";
    for(int i=0;i<input;i++){
        cin>>num;
        arr[i]=num;
    }
    //sort into descending order
    for(int i=0;i<input;i++){		
		for(int j=i+1;j<input;j++){
			if(arr[i]<arr[j]){
				temp  =arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	
	//set first two indexes to new arrays
   solution1[0]=arr[0];
   sum1+=arr[0];
   solution2[0]=arr[1];
   sum2+=arr[1];
   int dex1=1;
   int dex2=1;
   //add to the lower solution value
   
   for(int a=2;a<input;a++){
       if(sum1<sum2){
           solution1[dex1]=arr[a];
           dex1++;
           sum1+=arr[a];
       }
       else{
           solution2[dex2]=arr[a];
           dex2++;
           sum2+=arr[a];
       }
       
   }
   cout<<"Equal Group: ";
   if(sum1==sum2){
      for(int i=0;i<dex1;i++){
          cout<<solution1[i]<<" ";
      }
      cout<< "vs ";
      for(int i=0;i<dex2;i++){
          cout<<solution2[i]<<" ";
      }
   }
   else{
       cout<<"does not exist!"<<endl;
   }
   cout<<endl;
}
