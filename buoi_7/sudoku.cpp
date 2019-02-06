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
ifstream filein("in.dat");
ofstream fileout("out.dat");

int board[9][9];
bool used_in_col[9][9]; //
bool used_in_row[9][9]; //
bool used_in_square[9][9];
int square(int row,int col){
    if(row>=0 && row<=2 && col>=0 && col<=2) return 0;
    if(row>=0 && row<=2 && col>=3 && col<=5) return 1;
    if(row>=0 && row<=2 && col>=6 && col<=8) return 2;
    if(row>=3 && row<=5 && col>=0 && col<=2) return 3;
    if(row>=3 && row<=5 && col>=3 && col<=5) return 4;
    if(row>=3 && row<=5 && col>=6 && col<=8) return 5;
    if(row>=6 && row<=8 && col>=0 && col<=2) return 6;
    if(row>=6 && row<=8 && col>=3 && col<=5) return 7;
    return 8;
}
void show(){
    for(i,0,9){
        for(j,0,9) cout<<board[i][j]<<" ";
        cout<<endl;
    }
}
bool check(int row,int col,int num){
    return true; 

}

void setup_algorithm();
int main(){
    setup_algorithm();

    cin.close();
    cout.close();
    
    return 0;
}

void back_col(int row,int col){
    // cout<<"xet "<<row<<" "<<col<<endl;
    if(row == 9){show(); return;}
    if(col == 9) back_col(row+1,0);
    else if(board[row][col]==0){
        for(i,0,9){
            if(!used_in_col[col][i] && !used_in_row[row][i] && !used_in_square[square(row,col)][i]){
                // cout<<"dien hang"<<row<<" cot "<<col<< "gia tri " << i+1 <<endl;
                board[row][col]=i+1;
                used_in_col[col][i]=true;
                used_in_row[row][i]=true;
                used_in_square[square(row,col)][i]=true;
                back_col(row,col+1);
                used_in_col[col][i]=false;
                used_in_row[row][i]=false;
                used_in_square[square(row,col)][i]=false;
            }
        }
    }else back_col(row,col+1);
}

void setup_algorithm(){
    for(i,0,9)
    for(j,0,9){
        int x;
        cin>>x;
        board[i][j]=x;
        if(x!=0){
        used_in_col[j][x-1]=true;
        used_in_row[i][x-1]=true;
        used_in_square[square(i,j)][x-1]=true;
        }
    }
    back_col(0,0);
}