#include<bits/stdc++.h>
using namespace std;
// bool checkcycle(vector<int> adj[],int i,bool vis[],bool dfsvis[]){
//     vis[i]=true;
//     dfsvis[i]=true;
//     for(auto x:adj[i]){
//         if(!vis[x]){
//             bool check=checkcycle(adj,x,vis,dfsvis);
//             if(check) return true;
//         }
//         else if(dfsvis[x]){
//             return true;
//         }
//     }
//     dfsvis[i]=false;
//     return false;
// }
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
            adj[a].push_back(i);
        }
    }
    bool vis[n+1]={false};
    int par[n+1]={0};
    int src,dest;
    cin>>src>>dest;
    queue<int> q;
    q.push(src);
    vis[src]=1;
    while (!q.empty())
    {
        int p=q.front();
        q.pop();
        for(auto neighbour:adj[p]){
            if(!vis[neighbour]){
                q.push(neighbour);
                vis[neighbour]=1;
                par[neighbour]=p;
            }
        }
    }
    vector<int> ans;
    while (par[dest]!=0)
    {
        ans.push_back(dest);
        dest=par[dest];
    }
    reverse(ans.begin(),ans.end());
    for(auto x:ans) cout<<x<<" ";
    // for(int i=1;i<=n;i++){
    //     if(!vis[i]){
    //         bool detectcycle=checkcycle(adj,i,vis,dfsvis);
    //         if(detectcycle){
    //             cout<<"Yes";
    //             return 0;
    //         }
    //     }
    // }
    // cout<<"No";
    return 0;
}