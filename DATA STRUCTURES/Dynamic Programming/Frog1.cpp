#include<bits/stdc++.h>  
using namespace std;
const int N=1e5+10;
int h[N];
int dp[N];
int frog(int n){
    if(n==1) return 0;
    if(n==2) return abs(h[1]-h[2]);
    // int c=INT_MAX;
    // c=min(c,frog(n-1)+abs(h[n-1]-h[n]));
    // if(n>1){
    //     c=min(c,frog(n-2)+abs(h[n-2]-h[n]));
    // }
    // return c;
    if(dp[n]!=-1) return dp[n];
    int c1=frog(n-1)+abs(h[n-1]-h[n]);
    int c2=frog(n-2)+abs(h[n-2]-h[n]);
    return dp[n]=min(c1,c2); 
}
int main(){
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    cout<<frog(n);
    return 0;
}