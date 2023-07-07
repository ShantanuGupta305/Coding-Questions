#include<iostream>
using namespace std;
void str(string s){
    if(s.length()==0){
        return;
    }
    string r=s.substr(1);
    str(r);
    cout<<s[0];
}
int main(){
    str("binod");
    return 0;
}