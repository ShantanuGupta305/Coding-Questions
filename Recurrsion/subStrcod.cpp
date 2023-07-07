#include<iostream>
using namespace std;
void subseq2(string s,string ans){
    if(s.length()==0){
        cout<<ans<<endl;return;
    }
    char ch=s[0];int c=ch;string s1=s.substr(1);
    subseq2(s1,ans);
    subseq2(s1,ans+ch);
    subseq2(s1,ans+to_string(c));
}
int main(){
    subseq2("AB","");
    return 0;
}