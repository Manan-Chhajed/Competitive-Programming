void solve()
{
    int i, j, n;
    cin >> n;
    vector<int> k(n);
    fo(i, n) cin >> k[i];

    set<int> set;
    int ans = 0;
    i = 0, j = 0;
    while (i < n && j < n)
    {
        while (j < n && !set.count(k[j]))
        {
            set.insert(k[j]);
            ans = max(ans, j - i + 1);
            j++;
        }
        while (j < n && set.count(k[j]))
        {
            set.erase(k[i]);
            i++;
        }
    }
    cout << ans << nl;
}
