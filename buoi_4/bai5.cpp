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
int n,L;
int word;
void setup_algorithm(){
    cin>>n>>L;
    int lenght=0;
    int min_error=0;
    for(i,0,n){
        cin>>word;
        int n_lengt=lenght+word;
        if(n_lengt > L){
            min_error += (L- lenght);
            lenght=word;
        }else if(n_lengt==L) lenght=0;
        else lenght=n_lengt;
        // cout<<"i: "<<i<<" min_error: "<<min_error<<" lenght: "<<lenght<<endl;
    } 
    cout<<min_error+(L-lenght);
}