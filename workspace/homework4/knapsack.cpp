
#include <cmath>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(){
    int items = 0;
    int cap = 0;
    int max = 0;
    stringstream maxCombo;
    cout << "Enter a number of items: ";
    cin >> items;
	if(items ==0){
        cout<< "No items avalible!"<<endl;
        return 0;
    }
    cout << "Enter knapsack capacity: "; 
    cin >> cap;
    cout << "Enter weights and values of " << items << " items" << endl;
    if(cap == 0){
        cout << "No items will fit in knapsack!"<<endl;
        return 0;
    }
    int * weightArr;
    weightArr = new int[items-1];
    
    int * valuesArr;
    valuesArr = new int[items-1];
	
    for(int i =0; i < items; i++){
        cout << "Item " << i + 1 << ": ";
        cin >> weightArr[i];
        cin >> valuesArr[i];
    }
    cout << endl;
    int loops= pow(2,items);
    for(int i = 0; i <loops; i++)
    {
        string value = "";
        int totalCap = 0;
        int totalWeight = 0;
    
        for(int j = 0; j < items; j++){
            //figured out how to do subsets from geeksforgeeks page slightly edited it https://www.geeksforgeeks.org/finding-all-subsets-of-a-given-set-in-java/
            //mainly did this because i went a different way for homework 3 and was pretty confused with the concept of bitshifting
           if(value.length() > 0 && i & (1 << j)){ 
                value += ", ";                       
            }
            if(i & (1 << j)){  
                stringstream temp;
                temp << j + 1;
                value += temp.str();
                totalCap += weightArr[j];
                totalWeight += valuesArr[j];
            }
        }
        
        if (totalCap <= cap){
            cout << "set " << i + 1 << ":" << " {" << value << "}" << "\t=> capacity: " << totalCap << ", value: $" << totalWeight << endl;
            if(max < totalWeight){
                max = totalWeight;
                maxCombo.str(string());
                maxCombo << "Solution: {" << value << "}" << "\t=> capacity: " << totalCap << ", value: $" << totalWeight;
            }
        }
        else{
            cout << "Set " << (i+1) << ":" << " {" << value << "}" << "\t=> capacity: " << totalCap << " - over capacity, value: N/A" << endl;
        }
          
    }
    cout << endl << maxCombo.str() << endl; 
    
    return 0;   
}