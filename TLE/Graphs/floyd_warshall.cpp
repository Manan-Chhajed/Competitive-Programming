/* 
  - Floyd Warshall
    - cost[i][j] = min. cost to travel from i to j
    - can check -ve cycle using this algo
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
    int cost[n + 1][n + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                cost[i][j] = 0;
            }
            else {
                cost[i][j] = INT_MAX;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        cost[u][v] = min(cost[u][v], w);
    }
    for (int via = 1; via <= n; via++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (cost[i][k] == INT_MAX || cost[k][j] == INT_MAX) {
                    continue;
                }
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }
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
