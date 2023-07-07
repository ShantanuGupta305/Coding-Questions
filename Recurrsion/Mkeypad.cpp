#include<iostream>
using namespace std;
string keywords[]={"","./","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void keypad(string s,string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    char ch=s[0];
    string s1=keywords[ch-'0'];
    for(int i=0;i<s1.length();i++){
        keypad(s.substr(1),ans+s1[i]);
    }
}
int main(){
    keypad("23","");
    return 0;
}