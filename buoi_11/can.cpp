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
int n,S,a[MAX],x[MAX],Count=0, F[MAX],minn=MAX+1;
void show(){
    Count++;
    for(i,0,n){
        if(x[i]==1) cout<<" "<<a[i];
    }
    cout<<endl;
}
void check_best(){
    int t;
    for(i,0,n) t+=x[i];
    if(t<minn) {
        minn=t;
        for(i,0,n){
            F[i]=x[i];
        }
    }
}
bool check(){
    int temp=0;
    for(i,0,n){
        if(x[i]==1){
            temp+=a[i];
        }
    }
    return temp==S;
}
void back(int i){
    if(i==n){
        if(check()){
            show();
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
    cin>>n>>S;
    for(i,0,n){
        cin>>a[i];
    }
    back(0);
    if(minn==MAX*MAX) cout<<"NO SOLUSION";
    else{
        cout<<"cach tot nhat"<<endl;
        for(i,0,n)
        if(F[i]==1) cout<<a[i]<<" ";
    }
}