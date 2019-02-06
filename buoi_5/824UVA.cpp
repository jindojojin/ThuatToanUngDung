#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <fstream>
#include <queue>
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
int x,y,d,Area[8];
int dx[8]={0, -1, -1, -1,  0,  1, 1, 1};
int dy[8]={1,  1,  0, -1, -1, -1, 0, 1};
int cycle(int x){
    if(x==8) return 0;
    return x; 
}
void bfs(int u){
   int x=cycle(u+1);
   while(x!=u){
       if(Area[x]==1){
           cout<<x<<endl;
           return;
       }
       x=cycle(x+1);
   }
   cout<<u<<endl;//khong co duong nao khac nen phai quay lai
}
void setup_algorithm(){
    int xi,yi,si;
    while(cin>>x){
        if(x==-1) return;
        cin>>y>>d;
        for(i,0,8){
            cin>>xi>>yi>>si;
            xi=xi-x;
            yi=yi-y;
            for(j,0,8){
                if(dx[j]==xi && dy[j]==yi){
                    Area[j]=si;
                    break;
                }
            }
        };
        int r_d=(d>=3)?(d-4):(d+4);
        bfs(r_d);
    }
}