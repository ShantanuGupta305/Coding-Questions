#include<iostream>
using namespace std;
int main(){
    int a[]={1,2,3,4,5,6,7},n=7;
    for (int i = 1; i < n;)
    {
        if(a[i]>a[i-1]){
            int temp=a[i];
            a[i]=a[i-1];a[i-1]=temp;
        }
        if(a[i]>a[i+1]&&i<=n-2){
            int temp=a[i];
            a[i]=a[i+1];a[i+1]=temp;
        }
        i=i+2;
    }
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}