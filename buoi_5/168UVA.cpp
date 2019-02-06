#include <iostream>
#include <algorithm>
#include <stdlib.h>
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
ifstream filein("in.dat");
ofstream fileout("out.dat");

vector<vector<int> > Adj;
string str;

void setup_algorithm();
int main(){
    setup_algorithm();

    cin.close();
    cout.close();
    
    return 0;
}
map<char,int> m;
void setup_algorithm(){
    while(cin>>str){
        if(str=="#") return;
        char X,Y;
        int k;
        cin>>X>>Y>>k; 
        int i=0;
        int N=1;
        cout<<str<<endl;
        while(true){
            if(str[i]=='.') break;
            if(m[str[i]] == 0) m[str[i]]=N++;
            int x=m[str[i]];
            cout<<str[i];
            i+=2;
            cout<<x<<"here!"<<endl;
            cout<<str[2]<<" "<<i;
            while(str[i] != ';' && str[i] != '.'){
                if(m[str[i]] == 0) m[str[i]]=N++;
                Adj[x].push_back(m[str[i]]);
                i++;
                cout<<x<<"here!"<<endl;
            }
        }
        for(i,0,N){
            cout<<i<<endl;
            for(j,0,Adj[i].size()) cout<<j<<" ";
            cout<<endl;
        }
    }
}