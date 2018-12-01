#include <iostream>
using namespace std;

void print_time(short int x){
    if(x<10){ cout<<"000"<< x; return;}
    if(x<100){ cout<<"00"<< x; return;}
    if(x<1000){ cout<<"0"<< x; return;}
    if(x<10000){ cout<< x; return;}
}
short int setups[50][4]; // source , time , duration, target
short int time_call[50], extension[50];
short int used[50];
short int switch_to; // final extension system switch to

int switch_call(short int extension, short int time, short int Sum_of_set){
    for(short int set =0 ; set < Sum_of_set ; ++set){   // check all of system seting
        if( !used[set]
        &&  setups[set][0] == extension  
        &&  time >= setups[set][1] 
        &&  time <= setups[set][1] + setups[set][2]){
            used[set] = 1;
            switch_to = setups[set][3];
            switch_call(setups[set][3],time,Sum_of_set);
            used[set] = 0;
        }
    }
}

int main(){
    int T;
    cin>>T;
    
    cout<<"CALL FORWARDING OUTPUT"<<endl;
    for(int i=0; i< T ; i++){
        int temp;
        int count=0; //sum of setups
        int N=0;//sum of calls
        do{
            cin>>temp;
            if(temp != 0){
                setups[count][0]=temp;
                cin >> setups[count][1] >> setups[count][2] >> setups[count][3];
                count++;
                // used[count]=0;
            }else break;
        }while(true);
        do{
            cin>>temp;
            if(temp!= 9000){
                time_call[N]= temp;
                cin>> extension[N];
                N++;
            }else break;
        }while(true);

        
        cout<<"SYSTEM "<< i+1 <<endl;
        //set up algorithm
        for(int calling =0 ; calling < N; ++calling ){
            switch_to=0;
            switch_call(extension[calling], time_call[calling],count);
            if(switch_to != 0){
                if(extension[calling]==switch_to){cout<<"AT "; print_time(time_call[calling]) ;cout<<" CALL TO ";print_time(extension[calling]);cout <<" RINGS 9999" <<endl;}
                else {cout<<"AT "; print_time(time_call[calling]) ;cout<<" CALL TO ";print_time(extension[calling]);cout <<" RINGS "; print_time(switch_to) ;cout<<endl;}
            }else {cout<<"AT "; print_time(time_call[calling]) ;cout<<" CALL TO ";print_time(extension[calling]);cout <<" RINGS ";print_time(extension[calling]);cout <<endl;}
        }
        //end  
    }

    cout<<"END OF OUTPUT";
    return 0;
}