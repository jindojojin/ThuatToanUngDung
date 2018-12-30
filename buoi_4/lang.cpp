#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#define for(i,k,n) for(int i=k;i<n;i++)
#define cin filein
#define cout fileout
using namespace std;

ifstream filein("in.dat");
ofstream fileout("out.dat");
string str;
int words[20000];//words[x] : sum of words before position x
int k,x,y;
int main(){
    cin>>str;
    cin>>k;
    words[0]=1;
    for(i,1,str.size()){
        if(str[i]>=str[i-1]) words[i]=words[i-1];
        else words[i]=words[i-1]+1;
    }
    for(i,0,k){
        cin>>x>>y;
        cout<<words[y-1]-words[x-1]+1<<endl;
    }

    cin.close();
    cout.close();
    return 0;
}