#include<iostream>
using namespace std;
void subseq(string s,string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    char ch=s[0]; 
    subseq(s.substr(1),ans+ch);
    subseq(s.substr(1),ans+"");
}
int main(){
    subseq("ABC","");
    return 0;
}