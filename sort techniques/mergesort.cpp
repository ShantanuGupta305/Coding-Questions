#include<iostream>
using namespace std;
void merge(int arr[],int l,int mid,int r){
    int n1=mid-l+1,n2=r-mid,a[n1],b[n2];
    for(int i=0;i<n1;i++){
        a[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        b[i]=arr[mid+1+i];
    }
    int i=0,j=i,k=l;
    while (i<n1&&j<n2){
        if(a[i]>b[j]){
            arr[k]=b[j];
            k++;j++;
        }   
        else{
            arr[k]=a[i];
            k++;i++;
        }
    }
    while(i<n1){
        arr[k]=a[i];k++;i++;
    }
    while (j<n2){
        arr[k]=b[j];k++;j++;
    }
}
void mergesort(int arr[],int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}
int main(){
    int arr[]={5,4,3,2,1},l=0,r=5;
    mergesort(arr,l,r);
    for (int i = 0; i < r; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}