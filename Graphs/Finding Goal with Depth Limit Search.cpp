#include<bits/stdc++.h>
using namespace std;

vector<int> dfst;
bool flag = false;

void dls(vector<int> adj[], vector<int> &vis, int src, int target, int limit){
    if(flag) return;
    if(limit < 0) return;
    vis[src] = 1;
    dfst.push_back(src);
    if(src == target){
        flag = true;
        return;
    }
    for(auto &i: adj[src]){
        if(!vis[i]){
            dfs(adj, vis, i, target, limit - 1);
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
    int src, goal, limit; cin >> src >> goal >> limit;
    dls(adj, vis, src, goal, limit);
    if(flag){
        for(auto &i : dfst) cout << i << " ";
        cout << '\n';
    }
    else cout << -1 << '\n';
    return 0;
}
