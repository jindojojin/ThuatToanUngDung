#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <fstream>
#define for(i,k,n) for(int i=k;i<n;i++)
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
int n;
int p[1000],s[1000];
void setup_algorithm(){
    cin>>n;
    for(i,0,n) cin>>p[i];
    for(i,0,n) cin>>s[i];
    sort(p,p+n);
    sort(s,s+n);
    int result=0;
    for(i,0,n)
        result+= abs(p[i]-s[i]);
    cout<<result;
}