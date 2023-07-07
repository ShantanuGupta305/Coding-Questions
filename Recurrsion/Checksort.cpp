#include<iostream>
using namespace std;
bool checksort(int arr[],int n){
    if(n==1){
        return true;
    }
    else if(n<=0){
        return false;
    }
    bool restArray=checksort(arr+1,n-1);
    return (arr[0]<=arr[1])&& restArray;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    if(checksort(arr,n)){
        cout<<"Sorted";
    }
    else{
        cout<<"Not sorted";
    }
    return 0;
}