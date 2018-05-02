/*
 * Title: power.cpp
 * Abstract: program calculates power recursivly, algorithm from a 238 program
 * Author: Kyle Kern
 * ID: 1313
 * Date: 03/07/2018 
 */
#include <iostream>
#include <stdio.h>   
using namespace std;
int power(int x){
    if(x>0){
        return power(x-1)*2;
    }
    if(x==0){
        return 1;
    }
}

int main(){
    int input=0;
    cout<<"enter a number: ";
    cin>>input;
    if(input==0){
        cout<<"Result: 1"<<endl;
        return 0;
    }
    cout<<"Result: "<<power(input)<<endl;
    return 0;
}