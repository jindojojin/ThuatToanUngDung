#include <iostream>
using namespace std;
char a[100],b[100];
int m,n;
char result[100];
int temp=0;

int f(int i, int j){
    if(i==-1|| j==-1) return 0;
    if(a[i]==b[j]) {result[temp]= a[i]; temp++; return f(i-1,j-1)+1;}
    if(f(i-1,j) > f(i,j-1)) return f(i-1,j);
    else return (f(i,j-1));
}

int main(){
    cin>>m>>n;
    for(int i=0; i< m; i++)cin>>a[i];
    for(int i=0; i< n; i++) cin>>b[i];
    int lenght=  f(m-1,n-1); // độ dài xâu dài nhất
    cout<<lenght<<endl;
    for(int i=lenght-1;i>=0;i--) cout<<result[i];
}