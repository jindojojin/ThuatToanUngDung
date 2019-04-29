#include <iostream>
#include <fstream>
#define for(i,k,n) for(int i=k;i<n;i++)
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
const int MAX=20;
bool x[2*MAX],F[2*MAX];
int n,S,a[MAX][MAX],Count=0,minn=MAX*MAX;
void show(){
    for(i,0,n){
        cout<<F[i]<<" ";
    }
    cout<<endl;
    for(i,n,2*n){
        cout<<F[i]<<" ";
    }
    cout<<endl;
}
void check_best(){
    int t;
    for(i,0,2*n) t+=x[i];
    if(t<minn) {
        minn=t;
        for(i,0,2*n){
            F[i]=x[i];
        }
    }
}
bool check(){
    for(i,0,n){
        for(j,0,n){
            bool t=x[i]^x[n+j];
            if((t && a[i][j]==1) || (!t && a[i][j]==0)) return false;
        }
    }
    return true;
}
void back(int i){
    if(i==n*2){
        if(check()){
            check_best();
        }
        return;
    }
    // for(j,0,n){
        x[i]=1;
        back(i+1);
        x[i]=0;
        back(i+1);
    // }
}
void setup_algorithm(){
    cin>>n;
    for(i,0,n){
        for(j,0,n)
        cin>>a[i][j];
    }
    back(0);
    if(minn==MAX*MAX) cout<<"NO SOLUSION";
    else
    cout<<"so phep thuc hien"<<minn<<endl;
    show();
}