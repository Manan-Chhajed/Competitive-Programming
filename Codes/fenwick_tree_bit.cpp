struct BIT {
    int n;
    vector<int> tree;

    BIT(int n) {
        this->n = n;
        tree.assign(n + 1, 0);
    }

    BIT(vector<int>& a) : BIT(n) {
        for (int i = 1; i <= n; i++) {
            update(i, a[i]);
        }
    }

    int query(int k)  {
        int s = 0;
        while (k >= 1) {
            s += tree[k];
            k -= k & -k;
        }
        return s;
    }

    void update(int k, int x) {
        while (k <= n) {
            tree[k] += x;
            k += k & -k;
        }
    }
};
