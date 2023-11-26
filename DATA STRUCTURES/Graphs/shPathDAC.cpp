#include<bits/stdc++.h>
using namespace std;
void topodfs(vector<pair<int,int>> adj[],int node,stack<int>& s,bool vis[]){
    vis[node]=1;
    for(auto neighbour:adj[node]){
        if(!vis[neighbour.first]){
            topodfs(adj,neighbour.first,s,vis);
        }
    }
    s.push(node);
}
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> adj[n];
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        for(int j=0;j<m;j++){
            int a;
            cin>> a;
            int dis;
            cin>>dis;
            adj[i].push_back({a,dis});
        }
    }
    bool vis[n]={0};
    stack<int> s;
    topodfs(adj,0,s,vis);
    int src=1;
    int dist[n];
    for(int i=0;i<n;i++){
        dist[i]=INT_MAX;
    }
    dist[src]=0;
    while(!s.empty()){
        int top=s.top();
        s.pop();
        if(dist[top]!=INT_MAX){
            for(auto i:adj[top]){
                if(dist[top]+i.second<dist[i.first]){
                    dist[i.first]=dist[top]+i.second;
                }
            }
        }
    }
    cout<<endl<<"Ans"<<endl;
    for(int i=0;i<n;i++){
        cout<<dist[i]<<" ";
    }
    return 0;
}