#include <iostream>
using namespace std;
int s,d;
int amount;
int Posts[12];
int isSurplus;
int max_Surplus;

void calculate_amount(){
    int amount=0;
    for(int i =0 ; i< 12; i++){
        amount+=Posts[i];
    }
    if(amount >= max_Surplus){
        isSurplus=true;
        max_Surplus=amount;
    }
}

int sum_4_previous_months(int i){
    int sum=0;
    if(i>=4){ // only calculate if month in [5,6,7,8,9,10,11,12]
        for(int k=i-4; k<i; k++) sum+=Posts[k]; 
    }
    return sum;
}

void back(int i){
    if(i==12) calculate_amount();
    else{
            
        if(i<4 || (i>=4 && sum_4_previous_months(i) - d < 0)){
            Posts[i]= -d;   
            back(i+1);
        }
        
        if(i<4 || (i>=4 && sum_4_previous_months(i) + s < 0)){
            Posts[i]=s;
            back(i+1);
        }        
    }
}

int main(){
    while(cin>>s){
        cin>>d;
        isSurplus=false;
        max_Surplus=0;
        back(0);
        if(!isSurplus) cout<<"Deficit"<<endl;
        else{
            cout<<max_Surplus<<endl;
        }
    }
}