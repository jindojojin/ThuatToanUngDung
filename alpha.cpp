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


void setup_algorithm();
int main(){
    setup_algorithm();

    cin.close();
    cout.close();
    
    return 0;
}
vector<string> Alpha;
vector<string> Mix;
int A[2];
bool used[1000000];
void show(){
    // for(i,0,Mix.size()){
    //     cout<<A[i]<<" ";
    // }
    for(i,0,Mix.size()){
        cout<<"a"<<i<<"=("<<Mix[i]<<");"<<endl;
    }
    for(i,0,Mix.size()){
        cout<<"scale(a"<<i<<")";
        if(i<Mix.size()-1) cout<<"*";
    }
    cout<<endl<<"------------------------"<<endl<<endl;
    for(i,0,Mix.size()){
        cout<<"a"<<i<<"=("<<Mix[i]<<");"<<endl;
    }
    for(i,0,Mix.size()){
        cout<<"scale(a"<<i<<")";
        if(i<Mix.size()-1) cout<<"+";
    }
    cout<<endl<<"------------------------"<<endl<<endl;
    
}
void back(int i,int n){
    // if(i==n) {show();return;}
    for(i,0,Alpha.size()){
        Mix[0]=Alpha[i];
        A[0]=i;
        for(j,0,Alpha.size()){
            if(!used[j] && i!=j){
                used[j]=true;
                Mix[1]=Alpha[j];
                A[1]=j;
                for(k,j,Alpha.size()){
                    if(!used[k] && i!=j && k!=i){
                        // used[j]=true;
                        Mix[2]=Alpha[k];
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
    string str;
    while(cin>>str){
        Alpha.push_back(str);
    }
    Mix.resize(3);
    back(0,3);
    
}