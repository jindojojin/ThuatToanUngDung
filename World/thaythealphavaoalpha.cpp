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
ifstream filein("fin.dat");
ofstream fileout("out.dat");


void setup_algorithm();
int main(){
    setup_algorithm();

    cin.close();
    cout.close();
    
    return 0;
}
vector<string> alpha;
void setup_algorithm(){
    string a;
    while( cin>>a){
        alpha.push_back(a);
    }
    for(i,0,alpha.size()){
        "-ts_regression(close,vwap,60, lag = 0, rettype = 3))"
           cout<<"rank(ts_kurtosis("<<alpha[i]<<",50))"<<endl<<"----"<<endl;
           cout<<"rank(-ts_kurtosis("<<alpha[i]<<",50))"<<endl<<"----"<<endl;
           cout<<"rank(ts_kurtosis("<<alpha[i]<<",100))"<<endl<<"----"<<endl;
           cout<<"rank(-ts_kurtosis("<<alpha[i]<<",100))"<<endl<<"----"<<endl;
           cout<<"rank(ts_kurtosis("<<alpha[i]<<",150))"<<endl<<"----"<<endl;
           cout<<"rank(-ts_kurtosis("<<alpha[i]<<",150))"<<endl<<"----"<<endl;
           cout<<"rank(ts_kurtosis("<<alpha[i]<<",200))"<<endl<<"----"<<endl;
           cout<<"rank(-ts_kurtosis("<<alpha[i]<<",200))"<<endl<<"----"<<endl;
    }
}