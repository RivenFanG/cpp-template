#include<bits/stdc++.h>
using namespace std;

vector<int> dfst;

void dfs(vector<int> adj[], vector<int> &vis, int src){
    vis[src] = 1;
    dfst.push_back(src);
    for(auto &i: adj[src]){
        if(!vis[i]){
            dfs(adj, vis, i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector<int> adj[n + 1], vis(n + 1, 0);
    while(m--){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int src; cin >> src;
    dfs(adj, vis, src);
    for(auto &i : dfst) cout << i << " ";
    cout << '\n';
    return 0;
}
