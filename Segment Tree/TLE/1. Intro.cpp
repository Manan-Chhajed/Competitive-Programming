/* 
  1. Find the value by going down
  2. Update by going up
  
  For array representation total N leaf + N-1 internal nodes, so array size = 2*N (if array size multiple of 2)
  else 4N
*/

vector<int> segTree;
int merge(int l, int r)
{
    return l + r;
}

void build(vector<int>& arr, int start, int end, int index)
{
    // Build the segment tree
    // TC is O(n)
    if (start == end)
    {
        segTree[index] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    int left = 2 * index, right = 2 * index + 1;
    build(arr, start, mid, left);                       // go down left
    build(arr, mid + 1, end, right);                    // go down right
    segTree[index] = merge(segTree[left], segTree[right]);
}

void update(vector<int>& arr, int start, int end, int index, int pos, int value)
{
    // Update at a given point in segment tree
    // TC is O(logn)
    if (start == end)
    {
        arr[pos] = value;
        segTree[index] = arr[pos];
        return;
    }
    int mid = (start + end) / 2;
    if (pos <= mid)
        update(arr, start, mid, 2 * index, pos, value);
    else
        update(arr, mid + 1, end, 2 * index + 1, pos, value);
    segTree[index] = merge(segTree[2 * index], segTree[2 * index + 1]);
}

int query(int start, int end, int index, int l, int r)
{
    // Give sum from l to r
    // TC is O(logn)
    // complete overlap [l ... start ... end ... r]
    if (start >= l && end <= r)
        return segTree[index];
    // disjoint
    if (l > end || r < start)
        return 0;
    int mid = (start + end) / 2;
    int leftAnswer = query(start, mid, 2 * index, l, r);
    int rightAnswer = query(mid + 1, end, 2 * index + 1, l, r);
    return merge(leftAnswer, rightAnswer);
}

void solve()
{
    int n;
    cin >> n;
    segTree.resize(4 * n, -1); // 2n if size is power of 2 else 4n
    vector<int> arr(n);
    for (auto &i : arr)
        cin >> i;

    build(arr, 0, n - 1, 1); // 1 is index of top node of segment tree
    debug(segTree)
    debug(arr)
    cout << query(0, n - 1, 1, 0, 2) << endl;
    update(arr, 0, n - 1, 1, 1, 3);
    debug(segTree)
    debug(arr)
    cout << query(0, n - 1, 1, 0, 2) << endl;
}
