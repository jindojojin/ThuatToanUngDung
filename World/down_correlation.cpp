// Chuowng trinh nay ket hop cac alpha bi correlation voi cac alpha bonus de giam correlation
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
ifstream bonus("bonus.dat");
ofstream fileout("out.dat");

vector<string> BonusList;
vector<vector<string> > AlphaList;
void setup_algorithm();
int main(){
    setup_algorithm();

    cin.close();
    bonus.close();
    cout.close();
    
    return 0;
}

void setup_algorithm(){
    // doc danh sach cac bonus;
    string s;
    while(bonus>>s){
        BonusList.push_back(s);
    }
    //doc danh sach alpha;
    vector<string> alpha;
    while(cin>>s){
        if(s!="----"){
            alpha.push_back(s);
        }else{
            AlphaList.push_back(alpha);
            alpha.clear();
        }
    }

    for(i,0,AlphaList.size()){
        for(j,0,BonusList.size()){
            for(k,0,AlphaList[i].size()-1){
                cout<<AlphaList[i][k]<<endl;
            }
            cout<<AlphaList[i][AlphaList[i].size()-1]<<"*"<<BonusList[j]<<endl;
            cout<<"----"<<endl;
            cout<<AlphaList[i][AlphaList[i].size()-1]<<"+"<<BonusList[j]<<endl;
            cout<<"----"<<endl;
        }
    }

}