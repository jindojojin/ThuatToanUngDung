#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <fstream>
#include <vector>
#include <stack>
#include <map>
#define for(i,k,n) for(int i=k;i<n;i++)
using namespace std;

#define cin filein
#define cout fileout
ifstream filein("in.dat");
ofstream fileout("out.dat");


void setup_algorithm();
int main(){
    setup_algorithm();

    cin.close();
    cout.close();
    
    return 0;
}
int n;
void setup_algorithm(){
    cin>>n;
}