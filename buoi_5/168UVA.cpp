#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <fstream>
#include <vector>
#include <stack>
#include <map>
// #define for(i,k,n) for(int i=k;i<n;i++)
using namespace std;

#define cin filein
#define cout fileout
ifstream filein("fin.dat");
ofstream fileout("out.dat");

void setup_algorithm();
int main(){
    setup_algorithm();

    cin.close();
    cout.close();
    
    return 0;
}
vector<vector<int> > adj;
int T_pos;//theseus postion
int M_pos; // Minotaur postion
int k;
bool traped[30];


void startgame(int step){
    if(step % k == 0 && step!=0) {
        traped[T_pos]=true;
        cout<< (char)('A'+T_pos) <<" ";
    }
    for(int i=0; i<adj[M_pos].size();i++){
        int n_M = adj[M_pos][i]; // new Minotaur's position
        if(!traped[n_M] && n_M!= T_pos){
            T_pos=M_pos;
            M_pos= n_M;
            startgame(step+1);
            return;
        }
    }
    cout<<"/"<<char(M_pos+'A')<<endl;
}

void reset(){
    adj.resize(30);
    for(int k=0;k<30;k++){
        adj[k].resize(0);
        traped[k]=false;
    }
}

void setup_algorithm(){
    char C;
    reset();
    while(true){
        cin>>C;
        if(C=='#') break;
        char t;
        cin>>t;// for  ':'
        int v= (int)(C - 'A');
        while(true){
            char c2;
            cin>>c2;
            if(c2==';')break;
            if(c2 == '.') {
                char a,b;
                cin>>a>>b>>k;
                T_pos=int(b-'A');
                M_pos=int(a-'A');
                startgame(0);
                reset();
                break;
            }else {
                int v2 = (int)(c2-'A');
                adj[v].push_back(v2);
            }
        }
    }
}