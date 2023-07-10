if (l <= r) 
{
    int mid = (l + r) / 2;

    if (arr[mid] == tar)
        return mid;

    if (arr[mid] > tar)
        return binarySearch(arr, l, mid - 1, x);

    return binarySearch(arr, mid + 1, r, x);
}
