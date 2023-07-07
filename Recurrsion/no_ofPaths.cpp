#include<iostream>
using namespace std;
int pathNo(int s,int e){
    if(s==e){
        return 1;
    }
    if(s>e){
        return 0;
    }
    int count=0;
    for(int i=1;i<=6;i++){
        count+=pathNo(s+i,e);
    }
    return count;
}
int main(){
    cout<<pathNo(0,3);
    return 0;
}