/* 
  # Euler tour - path traced by dfs (flat representation of tree in order of dfs)
  
------------------------------------------------------------------------------------------------------------------------------------------
  - Type 1
  - LCA of a and b is the lowest level node b/w first occurence of a and b
*/
vector<int> flat;
map<int, int> mp;
int idx = 0;
void dfs(int u, int par, vector<int> adj[])
{
    if (mp.find(u) == mp.end())
    {
        mp[u] = idx;
    }
    flat.pb(u);
    idx++;
    for (auto v : adj[u])
    {
        if (v == par) continue;
        dfs(v, u, adj);
        flat.pb(u);
        idx++;
    }
}

// TC --> O(n) for dfs + O(q * log(n)) for seqment tree query
void solve()
{
    int n;
    cin >> n;
    vector<int> adj[n + 1];
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, 0, adj);
    debug(flat);
    debug(mp);
}
/*
------------------------------------------------------------------------------------------------------------------------------------------
  - Type 2
  - B/w 2 occurrences of a node, there is the subtree of the node
*/
vector<int> flat;
map<int, pair<int, int>> mp;
int idx = 0;
void dfs(int u, int par, vector<int> adj[])
{
    // entering the node
    mp[u].F = idx;
    flat.pb(u);
    idx++;
    for (auto v : adj[u])
    {
        if (v == par) continue;
        dfs(v, u, adj);
    }
    // leaving the node
    mp[u].S = idx;
    flat.pb(u);
    idx++;
}

// TC --> O(n) for dfs + O(q * log(n)) for seqment tree query
void solve()
{
    int n;
    cin >> n;
    vector<int> adj[n + 1];
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, 0, adj);
    debug(flat);
    debug(mp);
}
/*
------------------------------------------------------------------------------------------------------------------------------------------
  
*/
