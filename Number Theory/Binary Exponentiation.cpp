/* Manan Chhajed */

#include <bits/stdc++.h>

using namespace std;
const int M = 1e9 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}

// 1LL is sort of a typecast as res * res can overflow
int binExpRecur(int a, int b)
{
    if (b == 0) return 1;

    int res = binExpRecur(a, b / 2);

    if (b & 1)
        return (a * (res * 1LL * res) % M) % M;
    else
        return (res * 1LL * res) % M;
}

/*
    3 ^ 13
    3 ^ (1101)
    3^8 * 3^4 * 3^0 * 3^1
*/
// TC O(log b)
int binExpIter(int a, int b)
{
    int ans = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = (ans * 1LL * a) % M;
        }
        a  = (a * 1LL * a) % M;
        b >>= 1;
    }
    return ans;
}

// double has precision issues
int32_t main()
{
    init_code();

    // double d = 1e24;
    // cout << fixed << setprecision(1) << d << endl;

    // pow(2, 3) --> returns a double so avoid using in CP

    /*
    int a = 2, b = 13;
    int ans = 1;
    for (int i = 0; i < b; i++)
    {
        ans *= a;
        ans %= M;
    }
    cout << ans << endl;

    // a ^ b --> TC O(log b) instead of O(b)
    */

    cout << binExpRecur(2, 100) << endl;
    cout << binExpIter(2, 100) << endl;

    return 0;
}
