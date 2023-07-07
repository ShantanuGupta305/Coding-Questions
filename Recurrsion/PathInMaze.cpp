#include<iostream>
using namespace std;
int count=0;
int countPath(int n,int i,int j){
    if(i==n-1&&j==n-1){
        return 1;
    }
    if(i>=n||j>=n){
        return 0;
    }
    // return count+=countPath(n,i+1,j)+countPath(n,i,j+1);     //by myself
    return countPath(n,i+1,j)+countPath(n,i,j+1);            //in video;
}
int main(){
    cout<<countPath(2,0,0);
    return 0;
}