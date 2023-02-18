void solve()
{
    ll i, j, k, n, m, x;
    cin >> n >> x;
    vll a(n + 1);
    fo(i, 1, n) cin >> a[i];
    vll dp(x + 1);

    // dp[i] --> min. coins to make sum = i
    // ans is dp[x]
    // TC --> no.of states * (1 + avg. no. of transitions)

    dp[0] = 1;
    for (i = 1; i <= x; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i - a[j] >= 0) dp[i] += dp[i - a[j]];
        }
        dp[i] %= MOD;
    }
    cout << dp[x] << nl;
}
