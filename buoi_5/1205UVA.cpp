#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <fstream>
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
int N,R;
int C[1000];
void setup_algorithm(){
    while(cin>>N){
        cin>>R;
        if(N==0 && R==0) return;
        for(i,0,N) cin>>C[i];
        int u,v;
        for(i,0,N) {
            cin>>u>>v;
            
        };
    }
}