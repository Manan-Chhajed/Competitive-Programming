// https://www.youtube.com/watch?v=Ya0W8ZMzjgc&list=PLmnu3CJ3CYKVi6azWmglXnpbm_9puabti&index=3
// Binary search for answer

/*
  -> Instead of sorted array, we have a boolean array:
  1. [ffffff.......ttttt] --> we can find index of last false/ first true in O(log n)
  2. [ttttt......ffffff] --> here last true/ first false in O(log n)









  Packing Rectangles
  https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/A
  
  If square of side k is enough then a sqauare of side k + 1 will also be enough
  it is of kind [ffffff.....ttttttt]
  
  Obsevation --> the no. of rect. can be filled is (k/h) * (k/w)
  Condition --> if (k/h) * (k/w) <= n
  
ull w, h, n;
bool helper(ull k)
{
    return ((k / h) * (k / w) >= n);
}

void solve()
{
    cin >> w >> h >> n;
    ull l, r, mid;
    // invariant : l is always false and r is alsways true
    l = 0, r = 1e19;

    while (l + 1 < r)
    {
        mid = (r + l) / 2;
        if (helper(mid))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    cout << r << nl;
}
  
  
  
  
  
  
  
  
 
  // Aggressive cows
  // https://www.spoj.com/problems/AGGRCOW/
  
  n locations and c cows. What is max possible min dist. b/w 2 cows
  
  Solution
    Binary search for max possible min dist.
    if a distance d is enough then d-1 is always enough
    
  Situation
    [ttttttttt........ffffffff] --> we need to find the last t
  
  Only problem is to find whether d is enough or not
  Greedy: Assign a location to current cow if dist. from prev. cow >= d. If we are able to assign >= C cows, then d is enough
  
  ll n, c;
vector<ll> a;
bool helper(ll k)
{
    ll prev = -1e10;
    ll cnt = 0;
    Fo(i, 1, n)
    {
        if (a[i] - prev >= k)
        {
            prev = a[i];
            cnt++;
        }
    }
    return (cnt >= c);
}

void solve()
{
    ll i;
    cin >> n >> c;
    a.assign(n + 1, 0);
    Fo(i, 1, n)
    {
        cin >> a[i];
    }

    ll l, r, mid;
    l = 0, r = 1e12;
    sort(all(a));
    // invariant l is always true and r is always false
    while (l + 1 < r)
    {
        mid = (l + r) / 2;
        if (helper(mid))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    cout << l << nl;
}
  
  







  // Allocate books
  // https://www.interviewbit.com/problems/allocate-books/
  
  Answer: min value of max. pages assigned to a student
  
  If i pages (max pages assgned to a student) is good enough to assign books to all studnets then i+1 pages is also enough
  f(x) = [fffff......ttttttt]
  f(i) is true means that I can assign atleast one book to each student such that max pages <= i
  
  Problem: check whether f(i) is true or not
  Greedy: greedily assign all the books to same person until the no. of pages he has exceeds i
  cnt is min. no. of students we can assign books
  if cnt <= b then true
  
  
*/
