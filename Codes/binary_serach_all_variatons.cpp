if (l <= r) 
{
    int mid = (l + r) / 2;

    if (arr[mid] == tar)
        return mid;

    if (arr[mid] > tar)
        return binarySearch(arr, l, mid - 1, x);

    return binarySearch(arr, mid + 1, r, x);
}

while (l <= r)
{
    ll mid = (l + r) >> 1;
    memset(dp, -1, sizeof dp);

    string lim = to_string(mid);
    ll nums = f(0, lim, 1) - 1; // find the nth number in a sequence
    if (nums >= n)
    {
        r = mid - 1;
        res = mid;
    }
    else
    {
        l = mid + 1;
    }
}
