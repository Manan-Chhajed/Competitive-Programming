/* 
  - Topo sort
    - Only for DAG

  - BFS (Kahn's algo)
    - Maintain an indegree array
    - 
*/
// KIND OF ERRORS, CHECK USACO GUIDE
void topoSort(int node, vector<int>& indegree, vector<int>& topo, vector<int>&vis, vector<int> adj[]) {
    queue<int> q;
    q.push(node);
    vis[node] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for (auto v : adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
                vis[v] = 1;
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    vector<int> indegree(n + 1, 0);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    vector<int> vis(n + 1, 0);
    vector<int> topo;
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0 && indegree[i] == 0) {
            topoSort(i, indegree, topo, vis, adj);
        }
    }
    for (auto it : topo) cout << it << " ";
    cout << endl;
}
/*
  - DFS
    - After dfs is done, insert in the stack 
    - Where to start the dfs from?
      - anywhere is fine
    - Handling multiple components?
      - maintain vis array
*/
void dfs(int u, stack<int>& st, vector<int>& vis, vector<int> adj[]) {
    vis[u] = 1;
    for (auto v : adj[u]) {
        if (vis[v]) continue;
        dfs(v, st, vis, adj);
    }
    // inserting in the stack after the dfs is over
    st.push(u);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> vis(n + 1, 0);
    stack<int> st;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, st, vis, adj);
        }
    }
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << "\n";
}
