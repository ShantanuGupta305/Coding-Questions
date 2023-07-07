#include<iostream>
using namespace std;
int tillingWay(int n){
    if(n<=0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    return tillingWay(n-1)+tillingWay(n-2);
}
int main(){
    cout<<tillingWay(4);
    return 0;
}