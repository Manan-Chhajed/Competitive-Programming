/* 
  Normal segment tree
  1. Point updates
  2. Range queries

  Now, what if?
  1. Update all the values from l to r            O(log n)
  2. Range sum                                    O(log n)

vector<int> segTree, lazy;
int merge(int a, int b)
{
    return a ^ b;
}

void build(vector<int>& arr, int start, int end, int index)
{
    // build the segment tree
    // time complexity = O(n)
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
    if (start == end) // leaf node
    {
        lazy[index] = -1;
        return;
    }
    lazy[2 * index] = lazy[index];
    lazy[2 * index + 1] = lazy[index];
    lazy[index] = -1;
}

void update(int start, int end, int index, int l, int r, int value)
{
    // update at a given point in segment tree
    // time complexity: O(logn)
    if (lazy[index] != -1)
    {
        segTree[index] = ((end - start + 1) & 1) ? lazy[index] : 0;
        propogate(start, end, index);
    }
    // my current node is in the most updated point
    if (start >= l && end <= r)
    {
        // complete overlap
        segTree[index] = ((end - start + 1) & 1) ? value : 0;
        lazy[index] = value;
        propogate(start, end, index);
        return;
    }
    if (start > r || end < l) 
    { 
        // disjoint
        return;
    }
    int mid = (start + end) / 2;
    update(start, mid, 2 * index, l, r, value);
    update(mid + 1, end, 2 * index + 1, l, r, value);
    segTree[index] = merge(segTree[2 * index], segTree[2 * index + 1]);
}
int query(int start, int end, int index, int l, int r) { // give sum from L to R
    // time complexity: O(logn)
    // complete overlap
    /// [l......start..... end.... r]
    if (lazy[index] != -1) {
        segTree[index] = ((end - start + 1) & 1) ? lazy[index] : 0;
        propogate(start, end, index);
    }
    if (start >= l && end <= r)
        return segTree[index];
    // disjoint
    if (l > end || r < start)
        return 0; // default value
    int mid = (start + end) / 2;
    int leftAnswer = query(start, mid, 2 * index, l, r);
    int rightAnswer = query(mid + 1, end, 2 * index + 1, l, r);
    return merge(leftAnswer, rightAnswer);
}
*/
