void solve()
{
    ll i, j, k, n, m, x;
    cin >> n >> x;
    vll a(n + 1);
    fo(i, 1, n) cin >> a[i];
    vll dp(x + 1, INF);

    // dp[i] --> min. coins to make sum = i
    // ans is dp[x]
    // TC --> no.of states * (1 + no. of transitions)
    // TC --> O(n * x)

    dp[0] = 0;
    for (i = 1; i <= x; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i - a[j] >= 0) dp[i] = min(dp[i], dp[i - a[j]] + 1);
        }
    }
    if (dp[x] == INF) dp[x] = -1;
    cout << dp[x] << nl;
}
