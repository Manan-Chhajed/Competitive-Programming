// https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
int peakIndexInMountainArray(vector<int>& arr) 
{
  int n = arr.size();
  int l = -1, r = n-1;
  while(l + 1 < r)
  {
    int mid = (l + r) >> 1;
    if(arr[mid] < arr[mid + 1]) l = mid; // if(arr[mid] <= arr[mid + 1]) works as well --> think what happens at the peak
    else r = mid;
  }
  return r;
}

// https://codeforces.com/contest/1848/problem/D
// https://codeforces.com/contest/1848/submission/214152209
