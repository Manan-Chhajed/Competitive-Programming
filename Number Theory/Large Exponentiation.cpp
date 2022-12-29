
// Large exponentiation using Binary Multiplication
#include <bits/stdc++.h>

using namespace std;
const int M = 1e9 + 7;
using ll = long long;

void init_code() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}

/*
    if a <= 1e18
    a ^ b % M equivalent to ((a % M) ^ b) % M

    if M <= 1e18
    then binMultiply
*/

// normally a * a --> a + a + ... a times
// TC O(a)
// binMulitply --> TC O(log b)
/*
    eg. 3 * 13
        3 * (1101)
        3 * (8 + 4 + 0 + 1)
        similar to as binExpIter
*/
ll binMultiply(ll a, ll b)
{
    ll ans = 0;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = (ans + a) % M;
        }
        a  = (a + a) % M;
        b >>= 1;
    }
    return ans;
}

// TC --> log n * log n
ll binExpIter(ll a, ll b)
{
    ll ans = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = binMultiply(ans, a);
        }
        a  = binMultiply(a, a);
        b >>= 1;
    }
    return ans;
}

int32_t main()
{
    init_code();

    cout << binMultiply(2, 100) << endl;
    cout << binExpIter(2, 10) << endl;

    return 0;
}
