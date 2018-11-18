#include <iostream>
using namespace std;

int min_diference=99999999;
int up_down[500];
void calculate_difference(int a[][2], int N){
    int sum_up=0;
    int sum_down=0;
    for( int i =0 ; i< N ; i++){
        if(up_down[i]=1) {
            sum_up+=a[i][0];
            sum_down+=a[i][1];
        }else {
            sum_up += a[i][1];
            sum_down += a[i][0];
        } 
    }
    int difference = sum_down- sum_up;
    if(difference < 0) difference = difference*(-1);
    if (difference < min_diference) min_diference=difference;
}

void flip(int i,int a[][2], int N){
    if(i == N) calculate_difference(a,N);
    else{
        up_down[i]=1;
        flip(i+1,a,N);
        up_down[i]=0;
        flip(i+1,a,N);
    }
}

int main(){
    int N;
    cin>>N;
    int a[500][2]={};
    for(int i =0 ; i< N ; i++){
        cin>> a[i][0] >> a[i][1];
    }
    flip(0,a,N);
    cout<< min_diference;
    return 0;
}