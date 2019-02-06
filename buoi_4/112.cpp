#include <iostream>
#include <queue>
#include <fstream>
#define for(i,n) for(int i=0;i<n;i++)
#define cin filein
#define cout fileout
using namespace std;
ifstream filein("in.dat");
ofstream fileout("out.dat");
int M,N,Q;
int Map[1000][1000];
int Mark[1000];
int currentMark;


void GroupCity(int i){
    bool checked[1000];
    queue<int> Trace;
    Trace.push(i);
    while(!Trace.empty()){
        int k = Trace.front();
        Trace.pop();
        Mark[k]=currentMark;
        for(j,N)
            if(Map[k][j]==1 && !checked[j]){
                Trace.push(j);
                checked[j]=1;
                Mark[j]=currentMark;
            }
    }
}
int main(){
    
    cin>>N>>M;
    int x,y;
    for(i,M) {
        cin>>x>>y;
        Map[x-1][y-1]=1;
        Map[y-1][x-1]=1;
    }
    for(i,N){
        if(Mark[i]==0){
            currentMark++;
            GroupCity(i);
        }
    }
    cin>>Q;
    for(i,Q){
        cin>>x>>y;
        if(Mark[x-1]==Mark[y-1]) cout<<"1";
        else cout<<"0";
    }

    cin.close();
    cout.close();
    return 0;
}