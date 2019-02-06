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
struct R{ //Request to use class in (x,y)
    int x,y;
};
R req[1000];
bool cmp(R r1,R r2){
    return r1.x < r2.x;
}
int classes[1000];
int checked[1000];
void setup_algorithm(){
    cin>>n;
    for(i,0,n){
        cin>>req[i].x>>req[i].y;
    }
    sort(req,req+n,cmp);
    for(i,0,n){
        for(c,0,n)
            if(req[i].x>classes[c]){
                classes[c]=req[i].y;
                break;
            }
    }
    int total=0;
    for(i,0,n){
        if(classes[i]==0) break;
        total++;
    }
    cout<<total; //result here

}