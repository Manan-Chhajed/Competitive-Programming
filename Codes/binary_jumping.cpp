void solve()
{
    int n, q;
    cin >> n >> q;

    int par[n + 1][31];
    for (int i = 1; i <= n; i++)
    {
        cin >> par[i][0];
    }

    for (int d = 1; d <= 30; d++)
    {
        for (int i = 1; i <= n; i++)
        {
            par[i][d] = par[par[i][d - 1]][d - 1];
        }
    }

    auto jump = [&](int x, int d)
    {
        for (int i = 0; i <= 30; i++)
        {
            if (d & (1 << i)) x = par[x][i];
        }
        return x;
    };

    for (int i = 1; i <= q; i++)
    {
        int x, k;
        cin >> x >> k;

        cout << jump(x, k) << "\n";
    }
}
