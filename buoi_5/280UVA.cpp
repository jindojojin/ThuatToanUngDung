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
ifstream filein("fin.dat");
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
    while(true){
        cin>>n;
        // cout<<"n: "<<n<<endl;
        if(n==0) break;
        Adj.resize(n);
        for(i,0,n) Adj[i].resize(0);
        int v1;
        while(true){
            cin>>v1;
            if(v1==0) break;
            // cout<<"dinh "<<v<<endl;
            int v2;
            while(true){
                cin>>v2;
                if(v2==0) break;
                Adj[v1-1].push_back(v2-1);
            }
        }
        int test;
        cin>>test;
        for(t,0,test){
            int v;
            cin>>v;
            // cout<<"test "<<v<<endl;
            for(i,0,n) check[i]=false;
            sum_check=0;
            dfs(v-1);
            cout<<n-sum_check;
            for(i,0,n){
                if(!check[i]) cout<<" "<<i+1;
            }
            cout<<endl;
        }
        // cin>>n;
    }
}