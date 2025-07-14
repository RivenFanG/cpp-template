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
            dls(adj, vis, i, target, limit - 1);
        }
    }
}

bool iddls(vector<int> adj[], int n, int src, int target){
    for(int i = 0; i <= INT_MAX; i++){
        vector<int> vis(n + 1, 0);
        dls(adj, vis, src, target, i);
        if(flag) return true;
        dfst.clear();
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector<int> adj[n + 1];
    while(m--){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int src, goal; cin >> src >> goal;
    if(iddls(adj, n, src, goal)){
        for(auto &i : dfst) cout << i << " ";
        cout << '\n';
    }
    else cout << -1 << '\n';
    return 0;
}
