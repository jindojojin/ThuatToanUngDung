#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <fstream>
#include <vector>
#include <stack>
#include <cmath>
#include <map>
#define for(i,k,n) for(int i=k;i<n;i++)
using namespace std;

#define cin filein
#define cout fileout
ifstream filein("in.dat");
ofstream fileout("out.dat");

int step[10001];

void setup_algorithm();
int main(){
    setup_algorithm();

    cin.close();
    cout.close();
    
    return 0;
}
void back(int n){
    // cout<<"back "<<n<<"step "<<step[n]<<endl;
    if(step[n]!=999999) return;
    for(i,2,sqrt(n)){
        if(n%i == 0){
            // cout<<"nhan "<<i<<endl;
            back(i);
            back(n/i);
            int x= step[i];
            int y= step[n/i];
            step[n] = min(step[n],max(x,y)+1);
        }
        
    }
    for(i,1,n/2+1){
        // cout<<"cong "<<i<<endl;
        back(i);
        back(n-i);
        int x= step[i];
        int y= step[n-i];
        step[n] = min(step[n],max(x,y)+1);
    }

}

void setup_algorithm(){
    int N;
    cin>>N;
    step[1]=0;
    step[2]=1;
    for(i,3,10001) step[i]=999999;
    back(N); 
    // for(i,0,N+1) cout<<step[i]<<endl;
    cout<<step[N];
}