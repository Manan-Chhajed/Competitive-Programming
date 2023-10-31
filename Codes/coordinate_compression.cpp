 // coordinate compression
vector<ll> d = a;
sort(d.begin(), d.end());
d.resize(unique(d.begin(), d.end()) - d.begin());
for (ll i = 0; i < n; ++i)
{
    a[i] = lower_bound(d.begin(), d.end(), a[i]) - d.begin();
}
//original value of a[i] can be obtained through d[a[i]]
// https://codeforces.com/blog/entry/84164
