#include<iostream>
using namespace std;
int main()
{
    int r1,r2,r3,r4;
    cin>>r1>>r2>>r3>>r4;
    if(r2!=r3)
        return -1;
    int a[r1][r2],b[r3][r4],c[r1][r4];
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<r2;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<r3;i++)
    {
        for(int j=0;j<r4;j++)
        {
            cin>>b[i][j];
        }
    }
    for(int i=0;i<r1;i++)
    {   int s=0,k=0,l=0;
        for(int j=0;j<r2;j++)
        {
            s=s+a[i][j]*b[j][k];
            if(k!=r4 && j==r2-1)
            {
                j=0;k++;
                c[i][l]=s;l++;s=0;
            }
        }
    }
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<r4;j++)
        {
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}