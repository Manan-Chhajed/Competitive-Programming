/* 
  DSU Applications
  - Kruskal's Algo
    - Add min. weight edges to DSU (if not connected add else leave)
    - We get the MST

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

class dsu {
    vector<int> parent, size, rank;

public:
    dsu(int n) {
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
            size.push_back(1);
            rank.push_back(0);
        }
    }

    int findUPar(int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findUPar(parent[node]); // path compression
    }

    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if (pu == pv) return;
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pv] += size[pu];
        }
    }

    void unionByRank(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if (pu == pv) {
            return;
        }
        if (rank[u] == rank[v]) {
            parent[pu] = pv;
            rank[pu]++;
        }
        else if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        }
        else {
            parent[pv] = pu;
        }
    }
};

void solve() {

}

int main() {
    cmc();
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
