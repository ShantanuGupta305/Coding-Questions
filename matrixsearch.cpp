#include<iostream>
using namespace std;
int main(){
    int t,r,c;
    cin>>r>>c;
    int a[r][c];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cin>>t;
    int m=0,n=c-1,f=0;
    while(1){
        if(t==a[m][n]){
            cout<<"Found";f=1;break;
        }
        else if(t<a[m][n])
            n--;
        else if(t>a[m][n])
            m++;
        if((m==r) || (n==-1)){
            break;
        }
    }
    if(f==0)
        cout<<"Not Found";
    return 0;
}