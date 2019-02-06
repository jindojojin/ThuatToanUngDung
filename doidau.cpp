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


void setup_algorithm();
int main(){
    setup_algorithm();

    cin.close();
    cout.close();
    
    return 0;
}
string str;
void replaceAll(std::string& str, const std::string& from, const std::string& to) {
    if(from.empty())
        return;
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
    }
}
map<string,string> dict;
void setup_algorithm(){
    dict["ả"]="a";
    dict["ẳ"]="ẳ";
    dict["ẩ"]="â";
    dict["ẻ"]="e";
    dict["ể"]="ê";
    dict["ỏ"]="o";
    dict["ổ"]="ô";
    dict["ở"]="ơ";
    dict["ỉ"]="i";
    dict["ủ"]="u";
    dict["ử"]="ư";
    dict["ỷ"]="y";
    dict["Ả"]="A";
    dict["Ẳ"]="Ă";
    dict["Ẩ"]="Â";
    dict["Ể"]="Ê";
    dict["Ẻ"]="E";
    dict["Ỏ"]="O";
    dict["Ổ"]="Ô";
    dict["Ở"]="Ơ";
    dict["Ỉ"]="I";
    dict["Ủ"]="U";
    dict["Ử"]="Ư";
    dict["Ỷ"]="Y";
// sac
    dict["ắ"]="ẳ";
    dict["ấ"]="â";
    dict["ế"]="ê";
    dict["ố"]="ô";
    dict["ớ"]="ơ";
    dict["ứ"]="ư";
    dict["Ắ"]="Ă";
    dict["Ấ"]="Â";
    dict["Ế"]="Ê";
    dict["Ố"]="Ô";
    dict["Ớ"]="Ơ";
    dict["Ứ"]="Ư";
//huyen
    dict["ằ"]="ẳ";
    dict["ầ"]="â";
    dict["ề"]="ê";
    dict["ồ"]="ô";
    dict["ờ"]="ơ";
    dict["ừ"]="ư";
    dict["Ằ"]="Ă";
    dict["Ầ"]="Â";
    dict["Ề"]="Ê";
    dict["Ồ"]="Ô";
    dict["Ờ"]="Ơ";
    dict["Ừ"]="Ư";
//nga
    dict["ã"]="a";
    dict["ẵ"]="ẳ";
    dict["ẫ"]="â";
    dict["ẽ"]="e";
    dict["ễ"]="ê";
    dict["õ"]="o";
    dict["ỗ"]="ô";
    dict["ỡ"]="ơ";
    dict["ĩ"]="i";
    dict["ũ"]="u";
    dict["ữ"]="ư";
    dict["ỹ"]="y";
    dict["Ã"]="A";
    dict["Ẵ"]="Ă";
    dict["Ẫ"]="Â";
    dict["Ễ"]="Ê";
    dict["Ẽ"]="E";
    dict["Õ"]="O";
    dict["Ỗ"]="Ô";
    dict["Ỡ"]="Ơ";
    dict["Ĩ"]="I";
    dict["Ũ"]="U";
    dict["Ữ"]="Ư";
    dict["Ỹ"]="Y";
//nang
    dict["ạ"]="a";
    dict["ặ"]="ẳ";
    dict["ậ"]="â";
    dict["ẹ"]="e";
    dict["ệ"]="ê";
    dict["ọ"]="o";
    dict["ộ"]="ô";
    dict["ợ"]="ơ";
    dict["ị"]="i";
    dict["ụ"]="u";
    dict["ự"]="ư";
    dict["ỵ"]="y";
    dict["Ạ"]="A";
    dict["Ặ"]="Ă";
    dict["Ậ"]="Â";
    dict["Ệ"]="Ê";
    dict["Ẹ"]="E";
    dict["Ọ"]="O";
    dict["Ộ"]="Ô";
    dict["Ợ"]="Ơ";
    dict["Ị"]="I";
    dict["Ụ"]="U";
    dict["Ự"]="Ư";
    dict["Ỵ"]="Y";
   str.assign((std::istreambuf_iterator<char>(cin)),
            std::istreambuf_iterator<char>());
    // replaceAll(str,"ấ","â");replaceAll(str,"ầ","â");replaceAll(str,"ẫ","â");replaceAll(str,"ậ","â");replaceAll(str,"ẩ","â");
    // replaceAll(str,"ắ","ă");replaceAll(str,"ằ","ă");replaceAll(str,"ẵ","ă");replaceAll(str,"ặ","ă");replaceAll(str,"ẳ","ă");
    // replaceAll(str,"ố","ô");replaceAll(str,"ồ","ô");replaceAll(str,"ỗ","ô");replaceAll(str,"ộ","ô");replaceAll(str,"ổ","ô");
    // replaceAll(str,"ớ","ơ");replaceAll(str,"ờ","ơ");replaceAll(str,"ỡ","ơ");replaceAll(str,"ợ","ơ");replaceAll(str,"ở","ơ");
    // replaceAll(str,"ị","i");replaceAll(str,"ọ","o");replaceAll(str,"ụ","u");replaceAll(str,"ạ","a");replaceAll(str,"ã","a");
    // replaceAll(str,"ế","ê");replaceAll(str,"ề","ê");replaceAll(str,"ễ","ê");replaceAll(str,"ệ","ê");replaceAll(str,"ể","ê");
    // replaceAll(str,"ứ","ư");replaceAll(str,"ừ","ư");replaceAll(str,"ữ","ư");replaceAll(str,"ự","ư");replaceAll(str,"ử","ư");
    // replaceAll(str,"Ấ","Â");replaceAll(str,"Ầ","Â");replaceAll(str,"Ẫ","Â");replaceAll(str,"Ậ","Â");replaceAll(str,"Ẩ","Â");
    // replaceAll(str,"Ắ","Ă");replaceAll(str,"Ằ","Ă");replaceAll(str,"Ẵ","Ă");replaceAll(str,"Ặ","Ă");replaceAll(str,"Ẳ","Ă");
    // replaceAll(str,"Ố","Ô");replaceAll(str,"Ồ","Ô");replaceAll(str,"Ỗ","Ô");replaceAll(str,"Ộ","Ô");replaceAll(str,"Ổ","Ô");
    // replaceAll(str,"Ớ","Ơ");replaceAll(str,"Ờ","Ơ");replaceAll(str,"Ỡ","Ơ");replaceAll(str,"Ợ","Ơ");replaceAll(str,"Ở","Ơ");
    // replaceAll(str,"Ứ","Ư");replaceAll(str,"Ừ","Ư");replaceAll(str,"Ữ","Ư");replaceAll(str,"Ự","Ư");replaceAll(str,"Ử","Ư");
    // replaceAll(str,"Ế","Ê");replaceAll(str,"Ề","Ê");replaceAll(str,"Ễ","Ê");replaceAll(str,"Ệ","Ê");replaceAll(str,"Ể","Ê");
    // replaceAll(str,"ý","y");replaceAll(str,"ỳ","y");replaceAll(str,"ỷ","y");replaceAll(str,"ỵ","y");replaceAll(str,"ỷ","y");
    // replaceAll(str,"ả","a");
    map<string,string>::iterator it= dict.begin();
    while(it != dict.end()){
        replaceAll(str,it->first,it->second);
        ++it;
    }
    cout<<str;
}