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
            cout<<"a=ts_sum(open>close,20)/ts_sum(open<close,20);" <<endl;
            cout<<"b=ts_sum(open>close,252)/ts_sum(open<close,252);"<<endl; 
            cout<<"rank(a/b)+"<<"scale("<<alpha[i]<<")"<<endl<<"----"<<endl;

            cout<<"a=ts_sum(open>close,20)/ts_sum(open<close,20);" <<endl;
            cout<<"b=ts_sum(open>close,252)/ts_sum(open<close,252);"<<endl; 
            cout<<"rank(a/b)+1.5*"<<"scale("<<alpha[i]<<")"<<endl<<"----"<<endl;

            cout<<"a=ts_sum(open>close,20)/ts_sum(open<close,20);" <<endl;
            cout<<"b=ts_sum(open>close,252)/ts_sum(open<close,252);"<<endl; 
            cout<<"rank(a/b)+1.3*"<<"scale("<<alpha[i]<<")"<<endl<<"----"<<endl;
            
            cout<<"a=ts_sum(open>close,20)/ts_sum(open<close,20);" <<endl;
            cout<<"b=ts_sum(open>close,252)/ts_sum(open<close,252);"<<endl; 
            cout<<"rank(a/b)+0.7*"<<"scale("<<alpha[i]<<")"<<endl<<"----"<<endl;

            cout<<"a=ts_sum(open>close,20)/ts_sum(open<close,20);" <<endl;
            cout<<"b=ts_sum(open>close,252)/ts_sum(open<close,252);"<<endl; 
            cout<<"rank(a/b)+0.5*"<<"scale("<<alpha[i]<<")"<<endl<<"----"<<endl;

            cout<<"a=ts_sum(open>close,20)/ts_sum(open<close,20);" <<endl;
            cout<<"b=ts_sum(open>close,252)/ts_sum(open<close,252);"<<endl; 
            cout<<"rank(a/b)*"<<"scale("<<alpha[i]<<")"<<endl<<"----"<<endl;
    }
}