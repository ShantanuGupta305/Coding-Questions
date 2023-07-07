#include<iostream>          //using euclids algorithm
using namespace std;
int gcd(int a,int b){
    int rem;
    while(1){
        rem=a%b;
        if(rem==0){
            break;
        }
        a=b;
        b=rem;
    }
    return b;
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<"Gcd="<<gcd(a,b);
    return 0;
}