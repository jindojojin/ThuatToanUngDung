#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <fstream>
#define for(i,k,n,s) for(int i=k;i<n;i+=s)
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
float l,w;
struct Pos{
    float x1;
    float x2;
};
int sum_p;
Pos p[10000];
bool cmp(Pos x, Pos y){
    return x.x1 <= y.x1;
}

void setup_algorithm(){
    while(cin>>n){
    sum_p=0;
    if(!n) break;
    cin>>l>>w;
    float x,r;
    for(i,0,n,1) {
        cin>>x>>r;
        if(2*r <= w) continue;
        float c= sqrt(r*r - (w/2)*(w/2));
        p[i].x1= x-c;
        p[i].x2= x+c;
    }
    sort(p,p+n,cmp);
    for(i,0,n,1) {
        // cout<<p[i].x1<<" "<<p[i].x2<<endl;
    }
    float last_covered=0;
    while(last_covered < l){
        bool find=false;
        float max_x2=last_covered;
        for(i,0,n,1){
            if(p[i].x1 <= last_covered && p[i].x2>max_x2){
                max_x2=p[i].x2;
                find=true;
                // cout<<"found: "<<p[i].x1<<" "<<p[i].x2<<" last_covered: "<<last_covered<<endl;
            }
        }
        if(!find){cout<<"-1"<<endl; break;}
        last_covered=max_x2;
        sum_p++;
    }
    if(last_covered >=l )cout<<sum_p<<endl;
    }
}
