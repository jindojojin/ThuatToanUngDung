#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <fstream>
#define for(i,k,n) for(int i=k;i<n;i++)
#define cin filein
#define cout fileout
using namespace std;
ifstream filein("in.dat");
ofstream fileout("out.dat");
void setup_algorithm_a();
void setup_algorithm_b();
int main(){
    setup_algorithm_b();
    cin.close();
    cout.close();
    return 0;
}

int  C, f, r, n;
int Pos[1000];

void setup_algorithm_a(){ //stop at each pos & take fuel enough to go next Pos
    cin>>C>>f>>r>>n;
    for(i,0,n) cin>>Pos[i];
    int total_time=0;
    for(i,0,n-1){
        int next=Pos[i+1]-Pos[i];
        total_time += next*f*r;
    }
    cout<<total_time;
}

void setup_algorithm_b(){ //stop & take full fuel only can't to go next Pos
    cin>>C>>f>>r>>n;
    for(i,0,n) cin>>Pos[i];
    int total_time=0;
    int left_fuel=0;
    for(i,0,n-1){
        int next=Pos[i+1]-Pos[i];
        if(left_fuel < next*f){
            total_time += (C-left_fuel)*r;
        }
    }
    cout<<total_time;
}