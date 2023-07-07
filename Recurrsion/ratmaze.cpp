#include<iostream>
using namespace std;
bool issafe(int** arr,int x,int y,int n){
    if(x<n && y<n && arr[x][y]==1){
        return true;
    }
    return false;
}
bool mazepath(int** arr,int x,int y,int n,int** sol){
    if(x==n-1&&y==n-1&&arr[x][y]==1){
        sol[x][y]=1;
        return true;
    }
    if(issafe(arr,x,y,n)){
        sol[x][y]=1;
        if(mazepath(arr,x+1,y,n,sol)){
            return true;
        }
        if(mazepath(arr,x,y+1,n,sol)){
            return true;
        }
        sol[x][y]=0;return false;
    }
    return false;
}
int main(){
    int n;cin>>n;
    int** arr=new int*[n];
    int** sol=new int*[n];
    for(int i=0;i<n;i++){
        arr[i]=new int[n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        sol[i]=new int[n];
        for(int j=0;j<n;j++){
            sol[i][j]=0;
        }
    }
    if(mazepath(arr,0,0,n,sol)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<sol[i][j]<<" ";
            }cout<<endl;
        }
    }
    else{
        cout<<"Chuha bach gaya zinda pahuch jate to mar jata vo";
    }
    return 0;
}
// #include<iostream>                               nahi hua
// using namespace std;
// bool ispossible(int i,int j,int n,int m[5][5],int** s[5][5]){
//     if(i==n-1&&j==n-1){
//         return true;
//     }
//     else if(i>=n||j>=n||m[i+1][j]==0||m[i][j+1]==0){
//         return false;
//     }
//     if(ispossible(i+1,j,n,m,&s)){
//         s[i][j]=1;
//     }
//     else if(ispossible(i,j+1,n,m,&s)){
//         s[i][j]=1;
//     }
// }
// int main(){
//     int m[5][5]={{1,0,1,0,1},
//                {1,1,1,1,1},
//                {0,1,0,1,0},
//                {1,0,0,1,1},
//                {1,1,1,0,1}},solm[5][5]={{0,0,0,0,0},
//                                         {0,0,0,0,0},
//                                         {0,0,0,0,0},
//                                         {0,0,0,0,0},
//                                         {0,0,0,0,0}},i=0,j=0;
//     ispossible(i,j,5,m,&solm);
//     for(int i=0;i<5;i++){
//         for(int j=0;j<5;j++){
//             cout<<solm[i][j]<<" ";
//         }cout<<endl;
//     }
//     return 0;
// }