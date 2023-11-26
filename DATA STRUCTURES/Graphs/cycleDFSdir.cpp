#include<bits/stdc++.h>
using namespace std;
bool checkcycle(vector<int> adj[],int i,bool vis[],bool dfsvis[]){
    vis[i]=true;
    dfsvis[i]=true;
    for(auto x:adj[i]){
        if(!vis[x]){
            bool check=checkcycle(adj,x,vis,dfsvis);
            if(check) return true;
        }
        else if(dfsvis[x]){
            return true;
        }
    }
    dfsvis[i]=false;
    return false;
}
int main(){
    int n;
    cin>>n;
    vector<int> adj[n+1];
    for(int i=1;i<=n;i++){
        int m;
        cin>>m;
        for(int j=0;j<m;j++){
            int a;
            cin>> a;
            adj[i].push_back(a);
        }
    }
    bool vis[n+1]={false},dfsvis[n+1]={false};
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            bool detectcycle=checkcycle(adj,i,vis,dfsvis);
            if(detectcycle){
                cout<<"Yes";
                return 0;
            }
        }
    }
    cout<<"No";
    return 0;
}