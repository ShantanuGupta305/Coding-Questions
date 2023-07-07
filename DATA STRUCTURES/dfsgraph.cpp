#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> g[N];
bool vis[N];
void dfs(int vertex){
    //Take action on veertex after entering the vertex
    cout<<vertex<<endl;
    vis[vertex]=true;
    for(auto child:g[vertex]){
        cout<<"par "<<vertex<<",child "<<child<<endl;
        if(vis[child]) continue;
        //take action on child before entering the child node
        dfs(child);
        //take action on child after exiting the child node
    }
    //Take action on veertex after exiting the vertex
}
int main(){
    int n,m,k;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int v1,v2;
        cin>>v1>>v2;
        if(i==0) k=v1; 
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    dfs(1);
    return 0;
}