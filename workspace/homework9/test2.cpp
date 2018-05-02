#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <list>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

int n, m;

int c[25][25];

int f[25][25]; // The table used for storing dp result

int robotCoinCollection_topdown(int n, int m) 
{
	if (n == 0)
		return c[0][m];
	if (m == 0)
		return c[0][n];
	
	return max (robotCoinCollection_topdown(n-1,m),
				robotCoinCollection_topdown(n, m-1)) + c[n][m];
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

void robotCoinCollection(int i, int j, int &max_sum, vector<int> &v)
{
	v.push_back(c[i][j]);
	
	if (i == n-1 && j == m-1) {
		int sum = 0;
		for (size_t k = 0; k < v.size(); ++k)
			sum += v[k] ;

		max_sum = max(max_sum, sum);
	}
	
	if (i < n)
		robotCoinCollection(i+1,j,max_sum,v);
	if (j < m)
		robotCoinCollection(i,j+1,max_sum,v);

	v.pop_back();
}

int robotCoinCollection_traversal()
{
	vector<int> v;
	int max_sum = 0;
	robotCoinCollection(0,0,max_sum,v);
	return max_sum;
}

int main(int argc, char* argv[])
{
     string fileName;
    cout<<"Please enter filename: ";
    cin>>fileName;
    ifstream file(fileName.c_str());
    file>>n;
    file>>m;
    int i=0;
    int j=0;
    while(!file.eof()){
        file >> c[i][j];
        i++;
        if(i==n){
            i=0;
            j++;
        }
    }
    for(int y=0;y<m;y++){
    for(int x=0;x<n;x++){
           if(c[x][y]==2){
               c[x][y]=-9;
           }
           //cout<<arr[x][y]<<" ";
       }
       //cout<<endl;
   }
	//cout << "robotCoinCollection_topdown   = " << 
	//		robotCoinCollection_topdown(n,m)  << endl;
	cout << "robotCoinCollection_bottomup  = " << 
			robotCoinCollection_bottomup(n,m)  << endl;
	cout << "robotCoinCollection_traversal  = " << 
			robotCoinCollection_traversal()  << endl;

	return 0;
}