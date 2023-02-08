ll n;
ll dp[1000005];

ll f(ll tar)
{
    if (tar == 0) return 1;

    if (dp[tar] != -1)return dp[tar];

    ll ans = 0;
    for (int i = 1; i <= 6; i++)
    {
        if (tar - i >= 0)
        {
            ans += (f(tar - i) % MOD);
        }
    }
    return dp[tar] = ans % MOD;
}

void solve()
{
    ll i, j;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << f(n) << nl;

    // Observations
    // 1. each throw has 6 options
    // 2. total n throws, O(n * 6)
}
