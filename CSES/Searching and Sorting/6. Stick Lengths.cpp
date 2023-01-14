It's similar to problems like make all the elements of an array equal.

1. sort the array
2. median nikal, done
3. if odd length, considering 0 based, median = n/2
4. if even length, median take n/2 -1 or n/2 same hi aayega answer.

void solve()
{
    ll i, j, n;
    cin >> n;
    vector<int> v(n);
    fo(i, n) cin >> v[i];
    sort(v.begin(), v.end());

    ll ans = 0;
    ll x = v[n / 2];
    fo(i, n)
    {
        ans += abs(v[i] - x);
    }
    cout << ans << nl;
}
