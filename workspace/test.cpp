#include <iostream>
#include <stdio.h>   
#include <math.h>
#include <stdlib.h>
#include <limits.h>
using namespace std;
int main() {
 int j=1;
for (int i = 1; i % 5 != 0; i += 6){
  cout<<j<<" ";
  j++;
 }
}