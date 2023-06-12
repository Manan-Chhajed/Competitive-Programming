// Negative edge weights (in directed) without negative cycles
// O((n-1)(m))

void BellmanFord(int n, int src, vector<pair<int, ll>> *edges, vector<ll>& dist, set<int>& negCycle)
{
    fill(all(dist), INF);
    dist[src] = 0;
    vector<pair<ll, pair<int, int>>> e;
    for (int i = 0; i < n; i++)
    {
        for (auto j : edges[i])
        {
            e.pb({j.S, {i, j.F}});
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (auto j : e)
        {
            dist[j.S.S] = min(dist[j.S.S], dist[j.S.F] + j.F);
        }
    }
    //checking negative cycle
    for (int i = 0; i < n; i++)
    {
        for (auto j : e) {
            if (dist[j.S.S] > dist[j.S.F] + j.F)
            {
                dist[j.S.S] = dist[j.S.F] + j.F;
                negCycle.insert(j.S.S);
            }
        }
    }
}
