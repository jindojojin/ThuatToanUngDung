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
ifstream file6("fin2.dat");
ifstream file8("fin3.dat");
ifstream file4("fin3.dat");

ofstream fileout("out.dat");


void setup_algorithm();
int main(){
    setup_algorithm();

    cin.close();
    cout.close();
    
    return 0;
}
vector<string> root;
vector<string> alpha_8;
vector<string> alpha_6;
vector<string> alpha_4;


void setup_algorithm(){
    string a;
    while(cin>>a){
        root.push_back(a);
    }
    while(file6>>a){
        alpha_6.push_back(a);
    }
    while(file8>>a){
        alpha_8.push_back(a);
    }
    while(file4>>a){
        alpha_4.push_back(a);
    }

    for(i,0,root.size()){
        for(j,0,alpha_8.size()){
            for(k,0,alpha_6.size()){
                for(h,0,alpha_4.size()){
                    cout<<"al="<<root[i]<<";"<<endl;
                    cout<<"bl="<<alpha_8[j]<<";"<<endl;
                    cout<<"cl="<<alpha_6[k]<<";"<<endl;
                    cout<<"dl="<<alpha_4[h]<<";"<<endl;
                    cout<<"scale(al)+scale(bl)+scale(cl)+scale(dl)"<<endl<<"----"<<endl;
                }
            }
        }
    }
}