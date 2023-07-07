#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int fr=0,lr=n-1,fc=0,lc=m-1;
    while (fr<=lr && fc<=lc)
    {
        for(int c=fc;c<=lc;c++)
        {
            cout<<a[fr][c]<<" ";
        }
        fr++;
        for(int r=fr;r<=lr;r++)
        {
            cout<<a[r][lc]<<" ";
        }
        lc--;
        for(int c=lc;c>=fc;c--)
        {
            cout<<a[lr][c]<<" ";
        }
        lr--;
        for(int r=lr;r>=fr;r--)
        {
            cout<<a[r][fc]<<" ";
        }
        fc++;
    }
    
    return 0;
}