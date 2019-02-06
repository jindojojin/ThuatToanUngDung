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

struct alpha{
    float pnl[6];
    string code;
};
struct alpha_m{
    float pnl;
    string code;
};

vector<alpha> Alpha;
vector<alpha_m> VA;
vector<string> Mix;
bool used[1000000];
int A[2];
bool cmp(alpha_m x, alpha_m y){
    return x.pnl>y.pnl;
}

void setup_algorithm();
int main(){
    setup_algorithm();

    cin.close();
    cout.close();
    
    return 0;
}
bool checkAlphaPerformance(alpha x){
    float old = x.pnl[0];
    for(i,1,5){
        if(x.pnl[i]< -3) return false;
        old=x.pnl[i];
    }
    return true;
}
void show(){
    alpha X;
    for(j,0,6) X.pnl[j]=Alpha[A[0]].pnl[j];
    for(i,0,Mix.size()){
        // cout<<A[i]<<" ";
        for(j,0,6){
            X.pnl[j]=(X.pnl[j]+Alpha[A[i]].pnl[j])/2;
        }
    }
    if(checkAlphaPerformance(X)){
        cout<<Alpha[A[0]].code<<"+"<<Alpha[A[1]].code<<"+"<<Alpha[A[2]].code<<endl;
    }
    // for(i,0,Mix.size()-1){
    //     cout<<Mix[i]<<"+";
    // }
    // cout<<Mix[Mix.size()-1]<<endl;
    
}
void back(int i,int n){
    // if(i==n) {show();return;}
    for(i,0,Alpha.size()){
        Mix[0]=Alpha[i].code;
        A[0]=i;
        for(j,0,Alpha.size()){
            if(!used[j] && i!=j){
                used[j]=true;
                Mix[1]=Alpha[j].code;
                A[1]=j;
                for(k,j,Alpha.size()){
                    if(!used[k] && i!=j && k!=i){
                        // used[j]=true;
                        Mix[2]=Alpha[k].code;
                        A[2]=k;
                        show();
                        // back(i+1,n);
                        // used[j]=false;
                    }
                }
                // back(i+1,n);
                used[j]=false;
            }
        }
        // show();
        used[i]=true;
    }
}
void setup_algorithm(){
    int n=27;
    Alpha.resize(n);
    for(i,0,n){
        for(j,0,6){
            // string a;
            // cin>>a;
            // // cout<<a;
            // string unit = a.substr(a.size()-1,1);
            // string num = a.substr(0,a.size()-1);

            // float b = strtof(num.c_str(),0);
            // // if(unit == "K") b*=1000;
            // if(unit == "B") b*=1000000;
            // if(unit == "M") b*=1000;
            // cout<<unit<<" "<<b<<endl;
            float b;
            cin>>b;
            Alpha[i].pnl[j]=b;
        }
    }
    for(i,0,n){
        cin>>Alpha[i].code;
        cout<<Alpha[i].code<<endl;
    }
    Mix.resize(3);
    back(0,3);
}