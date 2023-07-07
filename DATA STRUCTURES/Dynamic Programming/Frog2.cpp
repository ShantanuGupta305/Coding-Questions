#include<bits/stdc++.h>  
using namespace std;
const int N=1e5+10;
int h[N];
int dp[N];
int frog(int n,int k){
    if(n==1) return 0;
    // if(n==2) return abs(h[1]-h[2]);
    if(dp[n]!=-1) return dp[n];
    int c1=INT_MAX;
    for(int i=1;i<=k;i++)
        if(n-i>=1)
            c1=min(c1,frog(n-i,k)+abs(h[n-i]-h[n]));
    // int c2=frog(n-2)+abs(h[n-2]-h[n]);
    return dp[n]=c1; 
}
int main(){
    memset(dp,-1,sizeof(dp));
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    cout<<frog(n,k);
    return 0;
}