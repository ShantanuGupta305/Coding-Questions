#include <iostream>
using namespace std;
int knapsack(int n,int w[],int v[],int W){
    if(n==0||W==0){
        return 0;
    }
    else if(w[n-1]>W){
       return knapsack(n-1,w,v,W);
    }
    return max(knapsack(n-1,w,v,W-w[n-1])+v[n-1],knapsack(n-1,w,v,W));
}
int main(){
    int w[]={10,20,30},v[]={20,50,10},W=50;
    cout<<knapsack(3,w,v,W);
    return 0;
}