ll const N = 1e5 + 7;
ll t[4 * N];
ll merge(ll a, ll b)
{
    return a ^ b;
}

void build(vll& a, ll v, ll tl, ll tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        ll tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        t[v] = merge(t[v * 2], t[v * 2 + 1]);
    }
}

void update(ll v, ll tl, ll tr, ll pos, ll new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, new_val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        t[v] = merge(t[v * 2], t[v * 2 + 1]);
    }
}

ll query(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    ll tm = (tl + tr) / 2;
    ll ans = merge(query(v * 2, tl, tm, l, min(r, tm)), query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    return ans;
}

/* 
    class SegmentTree {
private:
    ll N;
    vector<ll> t;

    ll merge(ll a, ll b) {
        return max(a, b);
    }

    void build(vll& a, ll v, ll tl, ll tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            ll tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            t[v] = merge(t[v * 2], t[v * 2 + 1]);
        }
    }

    void updateHelper(ll v, ll tl, ll tr, ll pos, ll new_val) {
        if (tl == tr) {
            t[v] = new_val;
        } else {
            ll tm = (tl + tr) / 2;
            if (pos <= tm)
                updateHelper(v * 2, tl, tm, pos, new_val);
            else
                updateHelper(v * 2 + 1, tm + 1, tr, pos, new_val);
            t[v] = merge(t[v * 2], t[v * 2 + 1]);
        }
    }

    ll queryHelper(ll v, ll tl, ll tr, ll l, ll r) {
        if (l > r)
            return 0;
        if (l == tl && r == tr) {
            return t[v];
        }
        ll tm = (tl + tr) / 2;
        return merge(queryHelper(v * 2, tl, tm, l, min(r, tm)),
                     queryHelper(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }

public:
    SegmentTree(vll& a) {
        N = a.size();
        t.resize(4 * N);
        build(a, 1, 0, N - 1);
    }

    void update(ll pos, ll new_val) {
        updateHelper(1, 0, N - 1, pos, new_val);
    }

    ll query(ll l, ll r) {
        return queryHelper(1, 0, N - 1, l, r);
    }
};
*/
