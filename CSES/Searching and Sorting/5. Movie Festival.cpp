void solve()
{
    ll i, j, k, n, m, x;
    cin >> n;
    vector <pair<ll, ll>> v;
 
    fo(i, n)
    {
        ll a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    int prev, cnt = 0;
    fo(i, n)
    {
        if (i == 0)
        {
            prev = v[i].S;
            cnt++;
            continue;
        }
        if (v[i].F >= prev)
        {
            cnt++;
            prev = v[i].S;
        }
        else
        {
            prev = min<ll>(prev, v[i].S);
        }
    }
    cout << cnt << nl;
}
