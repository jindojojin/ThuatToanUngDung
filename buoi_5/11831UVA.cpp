#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
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
ifstream filein("fin.dat");
ofstream fileout("out.dat");

int m,n,k;
map<char,int> dict;

int A[1000][1000];
void setup_algorithm();
int main(){
    dict['.']=-1;
    dict['*']=-2;
    dict['#']=-3;
    dict['N']=0; //north
    dict['L']=3; //east
    dict['S']=2; //south
    dict['O']=1; //west

    setup_algorithm();

    cin.close();
    cout.close();
    
    return 0;
}

int sti,stj,dir;//start(i) start(j) direction
int sum_star;
int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};
void ch_dir(char X){
    if(X=='E') dir=dir+1; //re trai , bắc -> tây
    else dir=dir-1;
    if(dir>3) dir=0;
    if(dir<0) dir=3;
}
void move(){
    int x =sti+dy[dir];
    int y =stj+dx[dir];
    // cout<<"moved to "<<x<<" "<<y<<endl;
    if(A[x][y]==-3 || x <0 || x>=m || y<0 || y>=n){
        // cout<<"dung im"<<endl;
        return;
    }else{
        sti=x;
        stj=y;
        if(A[x][y]==-2) {
            sum_star++;
            A[x][y]=-1;
        }
    }
}

void setup_algorithm(){
    while(cin>>m){
        cin>>n>>k;
        if(m==0 && n==0 && k==0)return;
        string c;
        for(i,0,m){
            cin>>c;
            for(j,0,n){
                A[i][j]=dict[c[j]];
                // cout<<A[i][j]<<" ";
                if(dict[c[j]] >= 0){
                    sti=i; stj=j;
                    dir=dict[c[j]];
                }
            }
            // cout<<endl;
        }
        cin>>c;
        sum_star=0;
        for(i,0,k){
            // cout<<c[i];
           if(c[i]!='F'){
               ch_dir(c[i]);
           }else move();
        }
        // cout<<sti<<" "<<stj<<" "<<dir<<endl;
        cout<<sum_star<<endl;
    }
}