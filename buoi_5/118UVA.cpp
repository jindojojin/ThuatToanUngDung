#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <fstream>
#include <stack>
#include <map>
#define for(i,k,n) for(int i=k;i<n;i++)
#define cin filein
#define cout fileout
using namespace std;
ifstream filein("in.dat");
ofstream fileout("out.dat");
void setup_algorithm();
int main(){
    setup_algorithm();
    cin.close();
    cout.close();
    return 0;
}
int m,n,Map[51][51];
map<char,int> Direct;
map<int,char> RDirect;
int current_direction;
// char dr[4]={'E','W','S','N'};
int  dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
void change_direct(char C){
    if(C=='R') current_direction+= 1;
    else current_direction-= 1;
    if(current_direction>3) current_direction= 0;
    if(current_direction<0) current_direction= 3;
}

bool move(int* x, int* y){
    int lx=*x+dx[current_direction];
    int ly=*y+dy[current_direction];
    if(lx > m || ly > n || lx < 0 || ly < 0){
        if(Map[*x][*y]==-1){
            return true;
        }
        Map[*x][*y]=-1;
        cout<<*x <<" "<<*y<<" "<<RDirect[current_direction]<<" LOST"<<endl;
        return false;
    }
    *x=lx;
    *y=ly;
    return true;
}
void setup_algorithm(){
    Direct['E']=0;
    RDirect[0]='E';
    Direct['S']=1;
    RDirect[1]='S';
    Direct['W']=2;
    RDirect[2]='W';
    Direct['N']=3;
    RDirect[3]='N';
    cin>>m>>n;
    int x,y;
    char d;
    string h;
    while(cin>>x){
        cin>>y>>d>>h;
        // cout<<x<<y<<d<<h<<endl;
        current_direction=Direct[d];
        bool lost=false;
        for(i,0,h.size()){
            if(h[i]!='F') change_direct(h[i]);
            else if(!move(&x,&y)){lost=true; break;}
        }
        if(!lost) cout<<x<<" "<<y<<" "<<RDirect[current_direction]<<endl;
    }
}