#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
    int items = 0, capacity =0;
    cout << "Enter a number of items: " << endl;
    cin >> items;
    
    /*
    if(items == 0){
        cout << "Invalid number of items. Please restart."
    }
    */
    
    cout << "Enter knapsack capacity: " << endl;
    cin >> capacity;
    
    int* weights = new int[items];
    int* values = new int[items];
   
    if(items == 1){
        cout << "Enter the weight and value of your " << "item: \n";
    } 
    else{
        cout << "Enter the weight and value of your " << items << " items: \n";
    }
    for(int i =0; i < items; i++){
        cout << "    Item " << i+1 << ": ";
        cin >> weights[i];
        cin >> values[i];
    }
    
    for(int j = 0; j < (items + 1); j++){
        if (j == 0){
            cout << "Set 1: {} => total capacity: 0, value: $0" << endl;
        }
        else{
            if(weights[j] < capacity){
                cout << "Set " << (j+1) << ": {" << j << "} => total capacity: "
                << weights[j] << " - over capacity, value: N/A " << endl;
            }
            else{
                cout << "Set " << (j+1) << ": {" << j << "} => total capacity: "
                << weights[j] << ", value: " << values[j] << endl;
            }
        }    
    }
}