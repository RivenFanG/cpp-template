#include<bits/stdc++.h>
using namespace std;
vector < int > bfs(vector < int > adj[], int src, int n) {
    vector < int > vis(n + 1, 0), bfst;
    queue < int > q;
    q.push(src);
    vis[src] = 1;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto & i: adj[node]) {
            if (!vis[i]) {
                q.push(i);
                vis[i] = 1;
            }
        }
        bfst.push_back(node);
    }
    return bfst;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector < int > adj[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector < int > traversal = bfs(adj, 1, n);
    for (auto & i: traversal) cout << i << " ";
    cout << '\n';
    return 0;
}
