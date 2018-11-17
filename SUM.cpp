#include <iostream>
using namespace std;
int used[8];
int A[8];
int Chess_Board[8][8];
int max_sum=-999999999;
bool ok(int i, int j){
    for(int k=0; k<i ; k++){
        if(A[k]-j == k-i || A[k]-j == i-k) return false;
    }
    return true;
}
void add_ressult(){
    int sum=0;
    for(int i =0 ; i<8 ; i++){
        sum += Chess_Board[i][A[i]];
    }
    if(sum> max_sum) max_sum=sum;
    // cout<< endl;
}
void set_queen(int i){
    if(i==8) add_ressult();
    else{
        for(int j= 0; j< 8; j++){
            if(!used[j] && ok(i,j)){
                A[i]=j;
                used[j] = 1;
                set_queen(i+1);
                used[j]=0;
            }
        }
    }
}

void get_input(){
    for(int i = 0; i< 8 ; i++){
        for(int j=0 ; j<8 ; j++){
            cin>>Chess_Board[i][j];
        }
    }
}

int main(){
    get_input();
    set_queen(0);
    // cout<< cnt;
    cout<<max_sum;
    return 0;
}

