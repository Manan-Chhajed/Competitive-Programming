// https://cses.fi/problemset/task/1648/

// Custom structure
// https://cses.fi/problemset/task/1735
// https://cses.fi/paste/75db46f4d43eb3567bc9bf/

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

// identity_element --> combine(x, I) = x
// identity_update --> apply(x, I) = x

template<class T, class U>
// T -> node, U->update.
struct Lsegtree {
    vector<T> st;
    vector<U> lazy;
    ll n;
    T identity_element;
    U identity_update;
    Lsegtree(ll n, T identity_element, U identity_update)
    {
        this->n = n;
        this->identity_element = identity_element;
        this->identity_update = identity_update;
        st.assign(4 * n, identity_element);
        lazy.assign(4 * n, identity_update);
    }

    T combine(T l, T r)
    {
        // change this function as required.
        T ans = (l + r);
        return ans;
    }

    void buildUtil(ll v, ll tl, ll tr, vector<T> &a)
    {
        if (tl == tr)
        {
            st[v] = a[tl];
            return;
        }
        ll tm = (tl + tr) >> 1;
        buildUtil(2 * v + 1, tl, tm, a);
        buildUtil(2 * v + 2, tm + 1, tr, a);
        st[v] = combine(st[2 * v + 1], st[2 * v + 2]);
    }

    // change the following 2 functions, and you're more or less done.
    T apply(T curr, U upd, ll tl, ll tr)
    {
        T ans = (tr - tl + 1) * upd;
        return ans;
    }

    U combineUpdate(U old_upd, U new_upd, ll tl, ll tr)
    {
        U ans = old_upd;
        ans = new_upd;
        return ans;
    }

    void push_down(ll v, ll tl, ll tr)
    {
        // for the below line to work, make sure the "==" operator is defined for it
        // if not an integer
        if (lazy[v] == identity_update) return;
        st[v] = apply(st[v], lazy[v], tl, tr);
        if (2 * v + 2 < 4 * n)
        {
            ll tm = (tl + tr) >> 1;
            lazy[2 * v + 1] = combineUpdate(lazy[2 * v + 1], lazy[v], tl, tm);
            lazy[2 * v + 2] = combineUpdate(lazy[2 * v + 2], lazy[v], tm + 1, tr);
        }
        lazy[v] = identity_update;
    }

    T queryUtil(ll v, ll tl, ll tr, ll l, ll r)
    {
        push_down(v, tl, tr);
        if (l > r)return identity_element;
        if (tr < l or tl > r)
        {
            return identity_element;
        }
        if (l <= tl and r >= tr)
        {
            return st[v];
        }
        ll tm = (tl + tr) >> 1;
        return combine(queryUtil(2 * v + 1, tl, tm, l, r), queryUtil(2 * v + 2, tm + 1, tr, l, r));
    }

    void updateUtil(ll v, ll tl, ll tr, ll l, ll r, U upd)
    {
        push_down(v, tl, tr);
        if (tr < l or tl > r) return;
        if (tl >= l and tr <= r)
        {
            lazy[v] = combineUpdate(lazy[v], upd, tl, tr);
            push_down(v, tl, tr);
        }
        else
        {
            ll tm = (tl + tr) >> 1;
            updateUtil(2 * v + 1, tl, tm, l, r, upd);
            updateUtil(2 * v + 2, tm + 1, tr, l, r, upd);
            st[v] = combine(st[2 * v + 1], st[2 * v + 2]);
        }
    }

    void build(vector<T> a)
    {
        assert(a.size() == n);
        buildUtil(0, 0, n - 1, a);
    }

    T query(ll l, ll r)
    {
        return queryUtil(0, 0, n - 1, l, r);
    }

    void update(ll l, ll r, U upd)
    {
        updateUtil(0, 0, n - 1, l, r, upd);
    }
};

void solve()
{
    ll n, q;
    cin >> n >> q;

    vector<ll> arr(n + 1, 0);
    for (ll i = 1; i <= n; i++) cin >> arr[i];

    Lsegtree<ll, ll> st(n + 1, 0, -1);

    st.build(arr);

    for (ll i = 1; i <= q; i++)
    {
        ll type;
        cin >> type;

        if (type == 1)
        {
            ll k, u;
            cin >> k >> u;
            st.update(k, k, u);
        }
        else
        {
            ll a, b;
            cin >> a >> b;
            cout << st.query(a, b) << "\n";
        }
    }
}

int main()
{
    io();

    ll t = 1;
    // cin >> t;

    while (t--) {
        cerr << t << endl;
        solve();
        cerr << endl;
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";
    return 0;
}
