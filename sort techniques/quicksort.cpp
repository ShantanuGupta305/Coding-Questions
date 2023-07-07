#include<iostream>
using namespace std;
int partition(int arr[],int l,int r){
    int pivot=arr[r];
    int i=l-1;
    for(int j=l;j<r;j++){
        if(arr[j]<arr[r]){
            i++;
            // arr[j]=arr[j]+arr[i];
            // arr[i]=arr[j]-arr[i];
            // arr[j]=arr[j]-arr[i];
            int temp=arr[j];arr[j]=arr[i];arr[i]=temp;
        }
    }
    // arr[i+1]=arr[i+1]+arr[r];
    // arr[r]=arr[i+1]-arr[r];
    // arr[i+1]=arr[i+1]-arr[r];
    int temp=arr[r];arr[r]=arr[i+1];arr[i+1]=temp;
    return i+1;
}
void quicksort(int arr[],int l,int r){
    if(l<r){
        int i=partition(arr,l,r);
        quicksort(arr,l,i-1);
        quicksort(arr,i+1,r);
    }
}
int main(){
    int arr[]={5,4,3,2,1},l=0,r=4;
    quicksort(arr,l,r);
    for(int i=0;i<=r;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}