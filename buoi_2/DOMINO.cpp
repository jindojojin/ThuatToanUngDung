#include <stdio.h>
#include <math.h>
using namespace std;
int a[1000][2];
int b[7][7];
int N;
int sum_up;
int sum_down;
int const_dif;
int min_dif;
int min_step;
int bit[10000];
void cal_difference(){
    int step=0;
    int dif=0;
    for(int i=0;i<N;i++){
        if(bit[i]==1){
            step++;
            dif+=(a[i][1]-a[i][0])-(a[i][0]-a[i][1]);
        }
    }
    dif=abs(const_dif+dif);
    printf("dif thay doi %d\n",dif);
    if( dif < min_dif){
        min_dif=dif;
        min_step=step;
    }
    if( dif == min_dif && step < min_step) min_step = step;
}
void lat(int i){
    if(i==N) {cal_difference(); return;};
    if(a[i][0]!=-1){
        bit[i]=1;
        lat(i+1);
        bit[i]=0;
        lat(i+1);
    }else lat(i+1);
}

int main(){
    scanf("%d",&N);
    int x,y;
    for(int i= 0 ; i< N ; i++){
        // scanf("%d %d",&a[i][0],&a[i][1]);
        // if(a[i][0]==a[i][1]){
        //     a[i][0]=-1;
        // }else{
        //     sum_up+=a[i][0];
        //     sum_down+=a[i][1];
        // }
        scanf("%d %d",&x,&y);
        b[x][y]++;        
    }
    int sum_domino=0;
    for(int i=0;i<7;i++){
        for(int j=0;j<i;j++){
            b[i][j]=abs(b[j][i]-b[i][j]);// chi xet nưa duoi cua ma tran
            if(b[i][j]>0){
                for(int k=0;k<b[i][j];k++){
                    a[sum_domino][0]=i;
                    sum_up+=i;
                    a[sum_domino][1]=j;
                    sum_down+=j;
                    sum_domino++;
                }
            }
        }
    }
    N=sum_domino;
    const_dif = sum_up-sum_down;
    min_dif = abs(const_dif);
    printf("N: %d\n",N);
    printf("const_dif: %d\n",const_dif);
    lat(0);
    printf("Min_dif: %d\n",min_dif);
    printf("%d\n",min_step);
    return 0;
}