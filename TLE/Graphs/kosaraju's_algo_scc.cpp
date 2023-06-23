/* 
  - SCC
*/
stack<int> st;
vll temp;
void dfs1(ll u, vll& vis, vll adj[])
{
    vis[u] = 1;
    for (auto v : adj[u])
    {
        if (vis[v]) continue;
        dfs1(v, vis, adj);
    }
    st.push(u);
}
 
void dfs2(ll u, vll& vis, vll adj[])
{
    vis[u] = 1;
    temp.pb(u);
    for (auto v : adj[u])
    {
        if (vis[v]) continue;
        dfs2(v, vis, adj);
    }
}
 
void solve()
{
    ll i, j, k, n, m;
    cin >> n >> m;
    vll adj[n + 1], adjT[n + 1];
    fo(i, 1, m)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adjT[v].pb(u);
    }
    vll vis(n + 1, 0);
    vvll scc;
    fo(i, 1, n)
    {
        if (!vis[i])
        {
            dfs1(i, vis, adj);
        }
    }
    debug(vis)
    fill(all(vis), 0);
    debug(vis)
    while (!st.empty())
    {
        ll u = st.top();
        st.pop();
        if (vis[u]) continue;
        dfs2(u, vis, adjT);
        debug(temp)
        scc.pb(temp);
        temp.clear();
    }
}
