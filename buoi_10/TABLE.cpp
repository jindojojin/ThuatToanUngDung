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

int R,C;
int A[400][400];
void setup_algorithm();
int main(){
    setup_algorithm();

    cin.close();
    cout.close();
    
    return 0;
}
int maxx;
int n;
void setup_algorithm(){
    maxx=0;
    char c;
    cin>>R>>C;
    for(i,0,R){
        for(j,0,C){
            cin>>c;
            if(c=='.') A[i][j]=1; else A[i][j]=0;
        }
    }
    for(i,0,R)
    for(j,0,C){
        if(A[i][j]==1){
            // cout<<"xet "<<i<<" "<<j<<endl;
            int max_d=R;
            int max_w=0;
            for(col,j,C){ // mỗi lần mở rộng chiều ngang thì xét chiều dài tối đa mở rộng được
                if(A[i][col]==0) break;
                max_w++;
                // cout<<"cot "<<col<<endl;
                int l=0;
                for(row,i,R){
                    // cout<<"i "<< row<<" l: "<<l<<" md: "<<max_d<<endl;
                    if(l>=max_d) break; // đảm bảo không vượt quá chiều cao của các cột đã xét trước đó
                    if(A[row][col]==1) l++;else break;
                }
                if( l< max_d) {max_d=l;} // :3
                // l=max_d;
                // cout<<"l: "<<l<<" md: "<<max_d<<" col:"<<col<<endl;
                if(2*(max_d+max_w) > maxx) maxx= 2*(max_d+max_w);
                // cout<<2*(max_d+max_w)<<endl;
            }
        }
        // cout<<"----------"<<endl;
    }
    cout<<maxx-1;   
    
}