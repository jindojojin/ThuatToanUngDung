#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <fstream>
#include <stack>
#include <vector>
#include <map>
#define for(i,k,n) for(int i=k;i<n;i++)
using namespace std;

#define cin filein
#define cout fileout
ifstream filein("in.dat");
ofstream fileout("out.dat");

vector<vector<int> > Adj;

void setup_algorithm();
int main(){
    setup_algorithm();

    cin.close();
    cout.close();
    
    return 0;
}
int n;
bool check[10000];
int sum_check;
void dfs(int x){
    for(i,0,Adj[x].size()){
        int y = Adj[x][i];
        if(!check[y]){
            check[y]=true;
            sum_check++;
            dfs(y);
        }
    }
}
void setup_algorithm(){
    while(cin>>n){
        cout<<n<<endl;
        // if(n==0) return;
        // Adj.resize(n);
        // int u;
        // while(true){
        //     cin>>u;
        //     int v;
        //     while(true){
        //         cin>>v;
        //         if(v==0) break;
        //         Adj[u-1].push_back(v-1);
        //     }
        // }
        // int test,x;
        // cin>>test;
        // cout<<"test  "<<test;
        // for(i,0,test){
        //     cin>>x;
        //     for(j,0,n) check[j]=false;
        //     sum_check=0;
        //     dfs(x-1);
        //     if(n-sum_check!=0){
        //     cout<<n-sum_check;
        //     for(j,0,n) if(!check[j]) cout<<" "<<j+1;
        //     cout<<endl;
        //     }else cout<<"0"<<endl;
        // }
    }
}