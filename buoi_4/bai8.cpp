#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <fstream>
#define for(i,k,n,s) for(int i=k;i<n;i+=s)
#define cin filein
#define cout fileout
using namespace std;
ifstream filein("in.dat");
ofstream fileout("out.dat");
void setup_algorithm();
int main(){
    setup_algorithm();
    cin.close();
    cout.close();
    return 0;
}
int n,m,P[1000];
bool cmp(int x,int y){ return x>y;};
void setup_algorithm(){
    cin>>n>>m;
   for(i,0,m,1) cin>>P[i];
   sort(P,P+m,cmp);
   int cost=0;
   int money=0;
   for(i,0,m,1){
       if(i+1 > n){break;}
       else if(P[i]*(i+1) > money){
           cost=P[i];
           money= cost*(i+1);
       }
   }
   cout<<cost<<" "<<money<<endl;
}
