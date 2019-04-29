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
int n;
int A[1000][1000];
bool used[1000][1000];
int R[3][2];
int total;
bool check_path(int a, int b){
    int x=R[a][0];
    int y=R[a][1];
    int x1=R[b][0];
    int y1=R[b][1];
    if(y==y1){
        int a = ((x+x1)-abs(x-x1))/2;
        int b = ((x+x1)+abs(x-x1))/2;
        for(i,a,b+1) {
            if(A[i][y]==0) return false;
        }
    }else if(x==x1){
        int a = ((y+y1)-abs(y-y1))/2;
        int b = ((y+y1)+abs(y-y1))/2;
        for(i,a,b+1) if(A[x][i]==0) return false;
    }
    else{
        double a=double(y-y1)/double(x-x1);
        double b=y-a*x;
        // cout<<a<<"x+ "<<b<<"=y"<<endl;
        int x0 = ((x+x1)-abs(x-x1))/2;
        int x2 = ((x+x1)+abs(x-x1))/2;
        for(i,x0,x2+1){
            int yy=a*i+b;
            if(A[i][yy]==0) return false;
        }
    }
    return true;
};
void show(){
    // ktra 3 điểm có thằng hàng không
    cout<<R[0][0]<<" "<<R[0][1]<<endl;
    cout<<R[1][0]<<" "<<R[1][1]<<endl;
    cout<<R[2][0]<<" "<<R[2][1]<<endl;
    float a = R[0][0] - R[1][0];
    float b = R[0][0] - R[2][0];
    float c = R[0][1] - R[1][1];
    float d = R[0][0] - R[2][1];
    if((d==0 && b==0) || (d!=0 && b!=0 && a/b == c/d)){
        return;
    };     
    // ktra xem giữa 2 điểm bất kì có đường hào không
    cout<<check_path(0,1)<<" ";
    cout<< check_path(0,2)<<" " ;
    cout<< check_path(1,2)<<endl;
    if(check_path(0,1) && check_path(0,2) && check_path(1,2))
    total++;


};
void back(int p){
    if(p ==3){ show(); return;}
    for(i,0,1000)
    for(j,0,1000){
        if(A[i][j]==1 && !used[i][j]){
            R[p][0]=i;
            R[p][1]=j;
            used[i][j]=true;
            back(p+1);
            used[i][j]=false;
        }
    }

}

void setup_algorithm(){
    cin>>n;
    int x,y,x1,y1;
    for(i,0,n){
        cin>>x>>y>>x1>>y1;
        // A[x][y]=1;
        // A[x1][y1]=1;
        // vẽ đường thẳng;
        if(y==y1){
            int a = ((x+x1)-abs(x-x1))/2;
            int b = ((x+x1)+abs(x-x1))/2;
            for(i,a,b+1) {
            //  cout<<i<<" "<<y<<endl; 
            A[i][y]=1;
            }
        }else if(x==x1){
            int a = ((y+y1)-abs(y-y1))/2;
            int b = ((y+y1)+abs(y-y1))/2;
            for(i,a,b+1) A[x][i]=1;
        }
        else{
            double a=double(y-y1)/double(x-x1);
            double b=y-a*x;
            // cout<<a<<"x+ "<<b<<"=y"<<endl;
            int x0 = ((x+x1)-abs(x-x1))/2;
            int x2 = ((x+x1)+abs(x-x1))/2;
            for(i,x0,x2+1){
                int yy=a*i+b;
                A[i][yy]=1;
            }
        }
    }

    // for(i,0,9){
    // for(j,0,9) cout<<A[i][j]<<" ";
    // cout<<endl;
    back(0);
    cout<<total;
}