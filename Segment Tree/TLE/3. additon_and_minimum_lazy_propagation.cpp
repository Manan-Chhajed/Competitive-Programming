vector<int> segTree, lazy;
int merge(int a, int b)
{
    return min(a, b);
}

void build(vector<int>& arr, int start, int end, int index)
{
    if (start == end)
    {
        segTree[index] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    int left = 2 * index, right = 2 * index + 1;
    build(arr, start, mid, left);                   // go down left
    build(arr, mid + 1, end, right);                // go down right
    segTree[index] = merge(segTree[left], segTree[right]);
}

void propogate(int start, int end, int index)
{
    if (start == end)
    {
        lazy[index] = 0;
        return;
    }
    lazy[2 * index] += lazy[index];
    lazy[2 * index + 1] += lazy[index];
    lazy[index] = 0;
}

void update(int start, int end, int index, int l, int r, int value)
{
    // update at a given point in segment tree
    // time complexity: O(logn)
    if (lazy[index] != 0)
    {
        segTree[index] += lazy[index];
        propogate(start, end, index);
    }
    // my current node is in the most updated point
    if (start >= l && end <= r)
    {
        // complete overlap
        segTree[index] += value;
        lazy[index] += value;
        propogate(start, end, index);
        return;
    }
    if (start > r || end < l) return;

    int mid = (start + end) / 2;
    update(start, mid, 2 * index, l, r, value);
    update(mid + 1, end, 2 * index + 1, l, r, value);
    segTree[index] = merge(segTree[2 * index], segTree[2 * index + 1]);
}

int query(int start, int end, int index, int l, int r)
{
    // give sum from L to R
    // time complexity: O(logn)
    // complete overlap
    /// [l......start..... end.... r]
    if (lazy[index] != 0)
    {
        segTree[index] += lazy[index];
        propogate(start, end, index);
    }
    if (start >= l && end <= r) return segTree[index];
    // disjoint
    if (l > end || r < start) return INF;

    int mid = (start + end) / 2;
    int leftAnswer = query(start, mid, 2 * index, l, r);
    int rightAnswer = query(mid + 1, end, 2 * index + 1, l, r);
    return merge(leftAnswer, rightAnswer);
}

void solve()
{
    int n, m;
    cin >> n >> m;
    segTree.resize(4 * n, -1);
    lazy.resize(4 * n, 0);
    vector<int> arr(n, 0);
    build(arr, 0, n - 1, 1);
    for (int i = 1; i <= m; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l, r, v;
            cin >> l >> r >> v;
            update(0, n - 1, 1, l, r - 1, v);
            debug(segTree)
            debug(lazy)
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << query(0, n - 1, 1, l, r - 1) << nl;
        }
    }
}
