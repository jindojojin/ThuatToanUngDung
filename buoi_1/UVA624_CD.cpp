#include <iostream>
using namespace std;
int max_time=0;
int songToWrite[20];
int final_songs[20]; // chi so dau tien se luu tong so bai hat duoc ghi
int M=0;
void show_songs(int a[],int n){
    int time=0;
    for(int i =0 ; i< n ; i++){
        if(songToWrite[i]==1){
            // cout<<a[i]<<" ";
            time+= a[i];
            
        }
    }
    // cout<<endl; 
    if(time >= max_time) {
        max_time= time;
        for(int i=0; i< n ; i++){
            final_songs[i]=songToWrite[i];
        }
    }
}
int cur_time=0;

void write_song(int a[],int n, int i){
    if(i == n ) show_songs(a,n);
    else{
            songToWrite[i] =0;
            write_song(a,n,i+1);
            if(cur_time + a[i] <= M){
                songToWrite[i]=1;
                cur_time+=a[i];
                write_song(a,n,i+1);
                cur_time-=a[i];
            }
    }
}

int main(){
    int song;
    while(cin>>M){
        cur_time=0;
        max_time=0;
        cin >> song;
        int A[20]={};
        for(int i =0 ; i< song; i++){
            cin>>A[i];
        }
        write_song(A,song,0);
        for(int i =0;i<song; ++i){
            if( final_songs[i] == 1)
            cout<< A[i]<<" ";
        }
        cout<<"sum:"<< max_time << endl;
    }
    
    return 0;
}