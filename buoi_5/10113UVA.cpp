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

typedef pair<int,int> ii;
typedef vector<ii> vii;
vector<vii> AdjList;
map<string,int> Dict;//ánh xạ từ tên đồ vật sang đỉnh đồ thị

int n;//sum of vertex in grahp
void setup_algorithm();
int main(){
    setup_algorithm();

    cin.close();
    cout.close();
    
    return 0;
}
int GCD(int x, int y){
    if(x==1 || y==1) return 1;
    while(x&&y) {
     if(x>y)x=x%y;
     else y=y%x;
    }
    return x+y;
}
int distance(int x, int y){
    for(i,0,AdjList[x].size()){
        if(AdjList[x][i].first == y) return AdjList[x][i].second;
    }
    return -1;
}
void dfs(int x,int y){
    for(z,0,AdjList[y].size()) {
        int v=AdjList[y][z].first;
        if(v != x && distance(x,v) == -1){
            int wx=AdjList[y][z].second*distance(x,y);
            int wv=distance(v,y)*distance(y,x);
            int gcd = GCD(wx,wv);
            ii X(v,wx/gcd);
            ii Z(x,wv/gcd);
            AdjList[x].push_back(X);
            AdjList[v].push_back(Z);
            dfs(x,v);
        } 
    }  
}

void setup_algorithm(){
    char c;
    string t1,t2;
    int n1,n2;
    while(cin>>c){
        if(c=='.') break;
        if(c=='!'){
            cin>>n1>>t1>>c>>n2>>t2;//c: "="
            if(Dict[t1]==0){
                Dict[t1]=n;
                n++;
                AdjList.resize(n);
                // AdjList[n].resize(0);
            }
            if(Dict[t2]==0){
                Dict[t2]=n;
                n++;
                AdjList.resize(n);
                // AdjList[n].resize(0);
            }
            int gcd = GCD(n1,n2);
            ii e1(Dict[t2],n1/gcd);
            ii e2(Dict[t1],n2/gcd);
            AdjList[Dict[t1]].push_back(e1);
            AdjList[Dict[t2]].push_back(e2);

        }
        if(c=='?'){
            cin>>t1>>c>>t2;
            int x = Dict[t1];
            int y = Dict[t2];
            for(i,0,AdjList[x].size())
                dfs(x,AdjList[x][i].first);
            int x1=distance(x,y);
            if(x1!=-1){ 
                int x2= distance(y,x);
                cout<<x1<<" "<<t1<<" = "<<x2<<" "<<t2<<endl;
            }
            else{
                cout<<"? "<<t1<<" = ? "<<t2<<endl;
            }
        }
    }
}