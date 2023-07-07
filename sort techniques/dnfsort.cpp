#include<iostream>
using namespace std;
int main(){
    int arr[]={1,1,2,0,0,1,2,2,1,0},l=0,m=l,h=9;
    while(m!=h){
        if(arr[m]==0){
            int temp=arr[m];
            arr[m]=arr[l];
            arr[l]=temp;
            l++;m++;
        }
        else if (arr[m]==1)
        {
            m++;
        }
        else if (arr[m]==2)
        {
            int temp=arr[m];
            arr[m]=arr[h];
            arr[h]=temp;
            h--;
        }
    }
    for(int i=0;;i++){
        if(i==10){
            break;
        }
        cout<<arr[i]<<" ";
    }
    return 0;
}