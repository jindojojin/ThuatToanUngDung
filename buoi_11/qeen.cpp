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
const int MAX=20;
int n;
int B[MAX];
bool used[MAX];
bool check(int i, int j){
    for(k,0,i){
        if(B[k]+k == i+j || B[k]-k == j-i) return false;
    }
    return true;
}
void show(){
    for(i,0,n){
        cout<<B[i]<<" ";
    }
    cout<<endl;
}
void set_queen(int i){
    if(i==n) show();
    for(j,0,n){
        if(!used[j] && check(i,j)){
            B[i]=j;
            used[j]=true;
            set_queen(i+1);
            used[j]=false;
        }
    }
}
void setup_algorithm(){
    cin>>n;
    set_queen(0);
}