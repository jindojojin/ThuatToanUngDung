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
ofstream fileout("fout.dat");

// Chương trình này lấy đầu vào là danh sách các dữ liệu thị trường của 1 công ty và tạo ra các alpha theo dạng rank(a/b);
// Bổ sung thêm zscore
void setup_algorithm();
int main(){
    setup_algorithm();

    cin.close();
    cout.close();
    
    return 0;
}
vector<string> data;
vector<string> alpha;
int n=2; //số alpha trộn vào nhau
int res[10]={}; // 2 phần tử data
bool used[1000];
void write_alpha(){
    // if(res[0]>=res[1]) return;
        // cout<<"scale("<<data[res[0]]<<")+scale("<<data[res[1]]<<")+scale("<<data[res[2]]<<")+scale("<<data[res[3]]<<")"<<endl<<"----"<<endl;
        // cout<<data[res[0]]<<"+"<<data[res[1]]<<"+"<<data[res[2]]<<"+"<<data[res[3]]<<endl<<"----"<<endl;
        // cout<<data[res[0]]<<"*"<<data[res[1]]<<"*"<<data[res[2]]<<"*"<<data[res[3]]<<endl<<"----"<<endl;
        for(lag,0,5)
        for(rettype,0,4)
        for(d,50,71){
        cout<<"-ts_regression("<<data[res[0]]<<","<<data[res[1]]<<","<<d<<",lag="<<lag<<",rettype="<<rettype<<")"<<endl<<"----"<<endl;
        cout<<"ts_regression("<<data[res[0]]<<","<<data[res[1]]<<","<<d<<",lag="<<lag<<",rettype="<<rettype<<")"<<endl<<"----"<<endl;
        }
}
void back(int i){
    if(i==n){
        write_alpha();
        return;
    }else{
        for(j,0,data.size()){
            if(!used[j]){
                used[j]=true;
                res[i]=j;
                back(i+1);
                // used[j]=false;
            }
        }
    }
}
void setup_algorithm(){
    string d;
    while(cin>>d){
        data.push_back(d);
        // cout<<d<<endl;
    }
    back(0);
}