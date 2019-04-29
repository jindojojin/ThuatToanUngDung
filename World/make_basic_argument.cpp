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
// tạo ra các toán tử từ các dữ liệu cơ bản hằng ngày.

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
        for(j,i+1,alpha.size()){
            cout<<"("<<alpha[i]<<"/"<<alpha[j]<<")"<<endl;
            cout<<"("<<alpha[j]<<"/"<<alpha[i]<<")"<<endl;
        }
    }
}