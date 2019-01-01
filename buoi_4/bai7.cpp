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
float l,w;
struct Pos{
    int x;
    float r;
};
Pos p[10000];
bool cmp(Pos x, Pos y){
    return x.x < y.x;
}
int full_cover(Pos x,Pos y){
    int l = abs(x.x-y.x);
    if(x.r+y.r <= l) return -1;//2 duong tron khong giao nhau
    if(l+x.r<y.r || l+y.r<x.r) return 0; //2 duong trong long nhau
    return (w*l*l*12 <= (x.r+y.r+l)*(x.r+l)*(y.r+l)*(x.r+y.r))?1:-1;// do dai cung giua 2 duong tron lon hon w
}
void setup_algorithm(){
    while(cin>>n){
    if(!n) break;
    cin>>l>>w;
    int x,r,Usage=0;
    for(i,0,n) {
        cin>>x>>r;
        if(2*r>w){
            p[Usage].x=x-r;
            p[Usage].r=r;
            Usage++;
        }
    }
    sort(p,p+Usage,cmp);
    int sum_p=0;
    Pos last_post;
    last_post.x=0;
    last_post.r=w/2;
    for(i,0,Usage){
        if(full_cover(last_post,p[i])!=-1){
            Pos temp=p[i];
            for(j,i+1,Usage){
                int ok=full_cover(last_post,p[j]);
                if(ok==-1) break;
                if(ok==0) continue;
                if(p[j].x+2*p[j].r > temp.x+2*temp.r) temp=p[j];
            }
            last_post = temp;
            sum_p++;
        }
    }
    cout<<sum_p<<endl;
    }
}