#include<bits/stdc++.h>
using namespace std;

vector<int> bfst;

bool bfs(vector<int> adj[], int src, int n, int target){
    vector<int> vis(n + 1, 0);
    queue<int> q;
    q.push(src);
    vis[src] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfst.push_back(node);
        if(node == target) return true;
        for(auto &i : adj[node]){
            if(!vis[i]){
                q.push(i);
                vis[i] = 1;
            }
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector<int> adj[n + 1];
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int target; cin >> target;
    if(bfs(adj, 1, n, target)){
        for(auto &i : bfst) cout << i << " ";
        cout << '\n';
    }
    else cout << -1 << '\n';
    return 0;
}
