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

bool used[1000][2];
int k;
typedef pair<int,int> ii;
map<char,ii> Dict;
string W;
void show(){

}

void back(int row,int col){
    if(row==k){show();return;}
    for(i,0,2){
        if(!used[row][i]){};
    }
}
void setup_algorithm();
int main(){
    ii a(0,0);
    ii b(0,1);
    ii c(1,0);
    ii d(1,1);
    Dict['A']=a;
    Dict['B']=b;
    Dict['C']=c;
    Dict['D']=d;
    cout<<Dict['A'].first;

    setup_algorithm();

    cin.close();
    cout.close();
    
    return 0;
}
string convert(int number ,int lenght){
    string  rslt;
    int c,
	b = number;
	do
	{   c = b % 2;
	    rslt.insert (0, 1, c+'0');
		b /= 2;
	} while (b > 0);
    while(rslt.size() < lenght+1){
	    rslt.insert(0,1,'0');
    }
    return rslt;
}
void setup_algorithm(){
    cin>>W>>k;
    int l= 2*W.size();
    for(i,1,k){
        cout<<convert(i,l)<<endl;
    }
    

}