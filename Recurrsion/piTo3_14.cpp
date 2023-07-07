#include<iostream>
using namespace std;
void replce(string s){
    if(s.length()==0){
        return;
    }
    if(s[0]=='p'&&s[1]=='i'){
        cout<<"3.14";replce(s.substr(2));
    }
    else{
        cout<<s[0];replce(s.substr(1));
    }
}
int main(){
    replce("pippxxppiixipi");
    return 0;
}