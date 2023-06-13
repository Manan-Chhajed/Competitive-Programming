/* 
A bfs trick!
void bfs(int root, vector<int> adj[])
{
    queue<pair<int, int>> q;
    q.push({root, -1});
    int level = 0;
    while (!q.empty())
    {
        int k = q.size();
        for (int i = 0; i < k; i++)
        {
            int node = q.front().F;
            int par = q.front().S;
            q.pop();
            cout << node << " ";
            for (auto child : adj[node])
            {
                if (child == par) continue;
                q.push({child, node});
            }
        }
        level++;
    }
    cout << "\nThe height is " << level << nl;
}

void solve()
{
    ll i, j, k, n, m;
    cin >> n;
    vector<int> adj[n + 1];
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    bfs(1, adj);
}
*/
