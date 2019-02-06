#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <fstream>
#include <stack>
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
int n,m,req;
int chair[1000][1000];
void extend_right(int i, int j){}
void extend_up(int i, int j){}
void setup_algorithm(){
   cin>>n>>m>>req;
   int tickets;
   for(i,0,req,1){
       cin>>tickets;
       for(i,0,n,1)
        for(j,0,m,1)
        if(chair[i][j]==0){
            while(tickets>0){
                extend_right(i,j);
                extend_up(i,j);
            }
        }
   }

}
