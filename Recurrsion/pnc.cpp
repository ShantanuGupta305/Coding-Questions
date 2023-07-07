#include<iostream>          // incomplete since different topic is used to solve this question
using namespace std;
void combinations(int num[],int ans[],int idx,int s){
    if(idx==s-1){
        
    }
    for(int i=idx;i<s;i++){
        swap(num[i],num[idx]);
        combinations(num,ans,idx+1,s);
        swap(num[i],num[idx]);
    }
}
int main(){
    int n;cin>>n;
    int num[n],ans[n];
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    combinations(num,ans,0,n);
    return 0;
}