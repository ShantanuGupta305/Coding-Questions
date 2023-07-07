#include<iostream>//done by my self
using namespace std;
void duplicate(string s){
    if(s.length()==0){
        return;
    }
    string s1=s.substr(1);
    if(s[0]!=s1[0]){
        cout<<s[0];
        duplicate(s1);
    }
    else{
        // cout<<s[0];
        duplicate(s1);
    }
}
/*
string duplicate(string s){         //in video
    if(s.length()==0){
        return "";
    }
    char ch=s[0];
    string ans=duplicate(s.substr(1));
    if(ch==ans[0]){
        return ans;
    }
    return (ch+ans);
}
*/
int main(){
    duplicate("aaaabbbeeecddd");
    return 0;
}