void solve()
{
    ll i, n;
    cin >> n;
    map<ll, ll> cnt;
    fo(i, n)
    {
        ll a, b;
        cin >> a >> b;
        cnt[a]++;
        cnt[b]--;
    }

    ll ans = 0, temp = 0;
    debug(cnt)
    for (auto it : cnt)
    {
        temp += it.S;
        ans = max(ans, temp);
    }
    cout << ans << nl;
}
