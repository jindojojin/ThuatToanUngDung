#include <iostream>
#include <stdlib.h>
#include <queue>
#include <fstream>
#define for(i,k,n) for(int i=k;i<n;i++)
#define cin filein
#define cout fileout
using namespace std;

ifstream filein("in.dat");
ofstream fileout("out.dat");
int n,m,k;
int virus[10][2];

int time(int x1,int y1,int x2,int y2){
    return abs(x1-x2) + abs(y1-y2);
}

int main(){
    cin>>n>>m;
    cin>>k;
    int total_time=0;
    for(i,0,k) cin>>virus[i][0]>>virus[i][1];
    for(row,0,n)
        for(col,0,m){
            int min_time=time(row,col,virus[0][0],virus[0][1]);
            for(vir,1,k){
                int t=time(row,col,virus[vir][0],virus[vir][1]);
                if(min_time > t) min_time=t;
            }
            if(total_time < min_time) total_time=min_time;
        }
    cout<<total_time;
    cin.close();
    cout.close();
    return 0;
}