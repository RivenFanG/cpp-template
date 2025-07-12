#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u][v] = w;
        adj[v][u] = w;
    }
    for(auto &i : adj){
        for(auto &j : i) cout << j << " ";
        cout << '\n';
    }
    return 0;
}
