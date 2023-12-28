/* 
  - Prefix sum doesn't work for non invertible operations
  - Sparse table works for invertible operations as well
    - Invertible means say you know answer for [1, 10] and [1, 15], can you find [10, 15]
  - What if operation is idempotent?
    - say you want answer for query 1 to 7, you can calculate for say 1 to 4(no. smaller than 7 that is a multiple of 2)
    - then you can find for 1 to 4 and any range such that you reach end of query array (i.e. reach 7)
    - so you can choose 1 to 4 and 3 to 7, since idempotent, overlap of the segment is fine
    - Idempotent means say f(x, x) = x, e.g. min, max, gcd, bitwise and, bitwise or
    - TC --> O(1 * op) for 1 query
    - Here op is the time for that particular query, say op for min is O(1) but for gcd is O(a) where a is larger of the 2 numbers
    - But still preprocessing of O(nlogn)
*/

// https://www.spoj.com/problems/RMQSQ/

#include<bits/stdc++.h>
using namespace std;

void io() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
#endif
}

using ll = long long;

const ll K = 22;
const ll N = 1e5 + 1;
ll st[K + 1][N];
ll lg[N + 1];

void sparsePre(vector<ll>& a)
{
    lg[1] = 0;
    for (ll i = 2; i <= N; i++)
    {
        lg[i] = lg[i / 2] + 1;
    }

    copy(a.begin(), a.end(), st[0]);

    // O(nlogn) preprocessing
    for (ll i = 1; i <= K; i++)
    {
        for (ll j = 0; j + (1 << i) <= N; j++)
        {
            st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
    }
}

ll query(ll l, ll r)
{
    // range min query
    ll i = lg[r - l + 1];
    ll mini = min(st[i][l], st[i][r - (1 << i) + 1]);
    return mini;

    // range sum query
    // ll sum = 0;
    // for (int i = K; i >= 0; i--)
    // {
    //     if ((1 << i) <= r - l + 1)
    //     {
    //         sum += st[i][l];
    //         l += 1 << i;
    //     }
    // }
}

void solve()
{
    ll n;
    cin >> n;

    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];

    sparsePre(a);

    ll q;
    cin >> q;
    for (ll i = 0; i < q; i++)
    {
        ll l, r;
        cin >> l >> r;

        cout << query(l, r) << endl;
    }
}

int main()
{
    io();

    int t = 1;
    // cin >> t;

    while (t--) {
        cerr << t << endl;
        solve();
        cerr << endl;
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";
    return 0;
}
