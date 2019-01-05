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
int n,B[100000],W[100000];
void setup_algorithm(){
   cin>>n;
   for(i,0,n,1) cin>>B[i];
   for(i,0,n,1) cin>>W[i];
   sort(B,B+n);
   sort(W,W+n);
   int k=1;
   int lastB=0;
   int lastW=0;
   for(w,1,n,1){
       if(W[w]>W[lastW] && W[w]>B[lastB]){ 
           for(b,lastB+1,n,1){
               if(B[b]>B[lastB] && B[b]>W[lastW]){
                   lastB=b;
                   lastW=w;
                   k++;
                   break;
               }
           }
       }
   }
   cout<<k<<endl;
}
