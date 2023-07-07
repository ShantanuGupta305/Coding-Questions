#include<iostream>
using namespace std;
int countPairing(int n){
    if(n==2||n==1||n==0){
        return n;
    }
    // return countPairing(n-1)+(n-2)*countPairing(n-1);        //By my self
    return countPairing(n-1)+(n-1)*countPairing(n-2);           //in video
}
int main(){
    cout<<countPairing(4);
    return 0;
}