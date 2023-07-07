#include<iostream>
using namespace std;
int fstoccr(int arr[],int n,int i,int k){
    if(i==n){
        return -1;
    }
    if(arr[i]==k){
        return i;
    }
    return fstoccr(arr,n,i+1,k);
}
int lstoccr(int arr[],int n,int i,int k){
    if(i==n){
        return -1;
    }
    int l=lstoccr(arr,n,i+1,k);
    if(l!=-1){
        return l;
    }
    if(arr[i]==k){
        return i;
    }
    return -1;
}
int main(){
    int arr[]={4,2,1,2,5,2,7};
    cout<<"1st occurance="<<fstoccr(arr,7,0,2)<<endl;
    cout<<"Last occurance="<<lstoccr(arr,7,0,2)<<endl;
    return 0;
}