#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <fstream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

#define cin filein
#define cout fileout
ifstream filein("fin.dat");
ofstream fileout("out.dat");

int n;
int A[1000][1000];
int dx[6]={-1,0,-1,0,1,1};
int dy[6]={-1,-1,0,1,0,1};
void floodfill(int x, int y){
    // cout<<"fill "<<x <<" " <<y<<endl;
    A[x][y]=-1;//đã xét
    for(int i=0;i<6;i++){
        int x2=x+dx[i];
        int y2=y+dy[i];
        if( x2 >= 0 && x2<n && y2 >=0 && y2<n && A[x2][y2] == 0){
            floodfill(x2,y2);
        }
    }

}
void game(int game){
    char c;
    for(int i=0; i<n;i++)
    for(int j=0;j<n;j++){
        cin>>c;
        if( c== 'b') A[i][j] =0;
        else A[i][j]=1;
    }
    for(int i=0;i<n;i++){
        if(A[0][i]==0){
            floodfill(0,i);
        }
    }
    for(int i=0;i<n;i++){
        if(A[n-1][i] == -1) {cout<<game<<" B"<<endl; return;}
    }
    cout<<game<<" W"<<endl;
}

void setup_algorithm();
int main(){
    setup_algorithm();

    cin.close();
    cout.close();
    
    return 0;
}

void setup_algorithm(){
    int i=1;
    while(true){
        cin>>n;
        if(n==0) return;
        game(i++);
    }
}
