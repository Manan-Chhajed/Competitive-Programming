/* Manan Chhajed */

#include <bits/stdc++.h>
// Policy based data structures
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

// Macros
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " "; _print(x); cerr << endl;
#define deb(x) cerr << #x << "=";
#else
#define debug(x)
#define deb(x);
#endif

#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define F first
#define S second

#define py cout << "YES\n";
#define pn cout << "NO\n";
#define pm cout << "-1\n";
#define fast_io() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
// #define int long long

// Aliases
using ll = long long;
using ull = unsigned long long;
using ld = long double;
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Constants
constexpr ll INF = 2e18;
constexpr ld EPS = 1e-9;
constexpr ll MOD1 = 998244353; // 1e9+7;

void init_code() {
    fast_io();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}

void _print(int a)
{
    cerr << a;
}

void _print(ll a)
{
    cerr << a;
}

void _print(char a)
{
    cerr << a;
}

void _print(string a)
{
    cerr << a;
}

void _print(bool a)
{
    cerr << a;
}

template<class T> void _print(vector<T> v1)
{
    cerr << "[ ";
    for (T i : v1)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

template<class T> void _print(set<T> s1)
{
    cerr << "[ ";
    for (T i : s1)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

void solve()
{
    int i, j, k, n;
}

int32_t main()
{
    init_code();

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
