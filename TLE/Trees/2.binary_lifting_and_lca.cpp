/* 
  # Print the kth parent of a node
  - Just do a dfs and find parent array, while(k--) node = par[node]
  
  # Now, what if we need to calculate for q such nodes --> TLE
  
  # Intuition of binary lifting
  - Store parents in power of 2
  - So, instead of k steps to reach a parent, now you can reach in log(k) steps
  - now store, par[node][x] i.e. x is 2^k th node
  - par[node][x] = par[par[node][x-1][x-1]
*/
void dfs(ll node, ll par, vll adj[], vector<vll> &dp)
{
    dp[node][0] = par;
    for (ll i = 1; i <= 16; i++)
    {
        dp[node][i] = dp[dp[node][i - 1]][i - 1];
    }
    for (auto it : adj[node])
    {
        if (it == par) continue;
        dfs(it, node, adj, dp);
    }
}

// TC --> O(nlogn) + O(qlogk)
//        dfs        queries
void solve()
{
    ll i, j, n, m;
    cin >> n;
    vll adj[n + 1];
    for (ll i = 1; i <= n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<vll> dp(n + 1, vll(17, 0)); // 17 is log(1e5)
    dfs(1, 0, adj, dp);
    ll q;
    cin >> q;
    while (q--)
    {
        ll node, k;
        cin >> node >> k; // print kth parent of node
        for (ll i = 16; i >= 0; i--)
        {
            if ((k >> i) & 1) node = dp[node][i];
        }
        cout << node << nl;
    }
}
/*  
  # LCA using binary lifting
  - bring them to same level using binary lifting
  - move a and b to every unequal node (16 to 0)
*/
void dfs(ll node, ll par, vll adj[], vector<vll> &dp, vll& level, ll l = 0)
{
    dp[node][0] = par;
    for (ll i = 1; i <= 16; i++)
    {
        dp[node][i] = dp[dp[node][i - 1]][i - 1];
    }
    level[node] = l;
    for (auto it : adj[node])
    {
        if (it == par) continue;
        dfs(it, node, adj, dp, level, l + 1);
    }
}

int getKthPar(int node, int k, vector<vll>& dp)
{
    for (ll i = 16; i >= 0; i--)
    {
        if ((k >> i) & 1) node = dp[node][i];
    }
    return node;
}

void solve()
{
    ll i, j, n, m;
    cin >> n;
    vll adj[n + 1];
    for (ll i = 1; i <= n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<vll> dp(n + 1, vll(17, 0)); // 17 is log(1e5)
    vll level(n + 1, 0);
    dfs(1, 0, adj, dp, level);
    ll q;
    cin >> q;
    while (q--)
    {
        ll a, b; // finding lca of a and b
        cin >> a >> b;
        if (level[a] > level[b]) swap(a, b);
        // a is at lesser level
        ll diff = level[b] - level[a];
        b = getKthPar(b, diff, dp);
        // now both a and b are at same level
        if (a == b)
        {
            cout << a << nl;
            continue;
        }
        for (int i = 16; i >= 0; i--)
        {
            if (dp[a][i] != dp[b][i])
            {
                a = dp[a][i];
                b = dp[b][i];
            }
        }
        cout << dp[a][0] << nl;
    }
}
