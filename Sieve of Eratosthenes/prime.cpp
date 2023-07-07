#include<iostream>
using namespace std;
void prime(int n){
    int primeN[100]={0};
    for(int i=2;i<=n;i++){
        if(primeN[i]==0){
            for(int j=i*i;j<=n;j+=i){
                primeN[j]=1;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(primeN[i]==0){
            cout<<i<<" ";
        }
    }cout<<endl;
}
int main(){
    int n;
    cin>>n;
    // cout<<n;
    prime(n);
    return 0;
}
