#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#define cin filein
#define cout fileout
ifstream filein("HANOI.INP");
ofstream fileout("HANOI.OUT");
int n;
int sum_step;
int A[10000];
char step1[20000];
char step2[20000];
void chuyen(int s,int f,int n){
    if(s==f) return;
    if(n==1){
        step1[sum_step]=(char)(s-1+'A');
        step2[sum_step]=(char)(f-1+'A');
        sum_step++;
        return;
    }
    else{
        chuyen(s,6-f-s,n-1);
        step1[sum_step]=(char)(s-1+'A');
        step2[sum_step]=(char)(f-1+'A');
        sum_step++;
        chuyen(6-f-s,f,n-1);
    }
}

void setupv2(int n,int f){
    if(n==0) return;
    else{
        if(A[n-1]!=f){
            setupv2(n-1,6-f-A[n-1]);
            step1[sum_step]=(char)(A[n-1]-1+'A');
            step2[sum_step]=(char)(f-1+'A'); 
            sum_step++;
        }
        setupv2(n-1,f);
    }

}

void setup(int i){
    //i la ten dia
    if(i==n) return;
    else{ chuyen(A[i-1],A[i],i);}
    setup(i+1);
}
void get_input(){
    cin>>n;
    char x;
    for(int i=0 ; i<n ; i++){
        cin>>x;
        A[i]=(int)(x-'A'+1);
    }
}
int main(){
    sum_step=0;
    get_input();
    // setup(1);
    // chuyen(A[n-1],3,n);
    setupv2(n,3);
    cout<<sum_step<<endl;
    for(int i=0; i< sum_step;i++){
        cout<<step1[i]<<step2[i]<<endl;
    }
    cin.close();
    cout.close();
}