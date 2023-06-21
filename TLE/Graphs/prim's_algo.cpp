/* 
  - Maintain a vis arrray
  - Maintain a priority queue of {wt, node, parent}, a min heap
  - Remove from priority queue and mark it visited
  - 
*/
#include<bits/stdc++.h>
using namespace std;

void cmc() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
#endif
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    priority_queue<vector<int>> pq;
    vector<int> vis(n + 1, 0);
    pq.push({0, 1, 0}); // {wt, node, par}
    int sum = 0;
    vector<pair<int, int>> edges;
    while (!pq.empty()) {
        int wt = -pq.top()[0];
        int node = pq.top()[1];
        int par = pq.top()[2];
        pq.pop();
        if (vis[node]) {
            continue;
        }
        vis[node] = 1;
        sum += wt;
        if (par != 0) {
            edges.push_back({node, par});
        }
        for (auto it : adj[node]) {
            if (vis[it.first] == 0) {
                pq.push({ -it.second, it.first, node});
            }
        }
    }
    cout << sum << "\n";
    for (auto it : edges) cout << it.first << " " << it.second << "\n";
}

int main() {
    cmc();
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
