#include<iostream>
using namespace std;
int main(){
    int a[]={1,3,2,3,4,1,6,4,3},max=a[0];
    for(int i=1;i<sizeof(a);i++){
        if(a[i]>max){
            max=a[i];
        }
    }cout<<"step1\n";
    int ans[sizeof(a)];int count[max]={0};
    for(int i=0;i<sizeof(a);i++){
        count[a[i]]++;
    }cout<<"step2\n";
    for(int i=1;i<=max;i++){
        count[i]=count[i]+count[i-1];
    }cout<<"step3\n";
    for(int i=sizeof(a)-1;i>=0;i--){
        ans[--count[a[i]]]=a[i];
    }cout<<"step4\n";
    for(int i=0;i<sizeof(a);i++){
        cout<<ans[i]<<" ";
    }cout<<"step5\n";
    return 0;
}