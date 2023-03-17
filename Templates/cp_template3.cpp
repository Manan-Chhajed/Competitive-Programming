/* Manan Chhajed */

#include <bits/stdc++.h>
// Policy based data structuans
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

/*

                ~ You don't know the power of the dark side! ~

..-..,'".-     BM\dF. jM@'    !MMM.&^'jjjM#*..`.              !*m.F.    `.....
-`.'^-".^.   ._'-".   ``       `"#.# .]MF.      _.  __-gg..      jMg.   ......
'......._   j#M' jMf       jg_jm..-`  .Mf_ ja   "`  .`  `^" ,_ 4g."@!.  ...,.,
',3&^jCgf ._`"`"'.         .` """!.   .`^^       .....        .""LTgJf.  =/<.,
_@#MMQK##-@"^                         ..                         .'QK_. .!$AGz
MM&&#0$#yF.                          !-M.    .gmMM@!               ."q. ..K#MD
ZM#ZM#$.                             q4M.    ..__,,yg_.              ^\. ..M0#
A0NWM@.                    jggp.    .,m*      .#MMMMM#'..              '  ."M0
BMM$@"                     !MM#'..   -*'      ."QMMMM#`..                 ..^$
BMMM'                      .^@#.'`   _     ,yy___````.                     . `
MMMP                        ...  j.  1.L   .""9*qwwwJ,.                     ..
@@@.                   .     ...P`,  .F`            .`.                     ..
0T`                   .P. . F`      :"~~-  ._.e.,wyyw..,,....
yg.                             '  _g0M0g. .-'`'^`Q$_
Mf                                .jMMMMML    .`-"0M#
@.                              . ."MMMM@^        ."".
f                              .    -.            ...
.                             .                 ._  ...
                            .           .        .    ..
                       ..  -'          .,              ..,   ..,.
                        `.          . ..*. . _     ,   .p_ .-,'jb.
_                     jgg, -'-+..--!.!!!` !' .~.      _0MM/.-.-/@.   .yyygggMM
M0gyy__________.      ^0M'                            "MM^  ...".     `^MMMMMM
MMMMMMMMMMMMMM'.                                                   ..        .

*/

// Macros
#ifndef ONLINE_JUDGE
#define debug(x)        cerr << #x << " "; _print(x); cerr << endl;
#define deb(x)          cerr << #x << "=";
#else
#define debug(x)
#define deb(x);
#endif

#define fo(i, a, b)     for (i = a; i <= b; i++)
#define Fo(i, k, n)     for (i = k; k <= n ? i <= n : i >= n; k <= n ? i += 1 : i -= 1)
#define F               first
#define S               second
#define pb              push_back
#define ppb             pop_back
#define pf              push_front
#define ppf             pop_front
#define mkp             make_pair
#define set_bits        __builtin_popcountll // __builtin_ffsll(x) returns 1 + least significant 1-bit of x
#define py              cout << "YES\n";
#define pn              cout << "NO\n";
#define all(x)          (x).begin(), (x).end()
#define all1(v)         (v).begin()+1, (v).end()
#define rall(x)         (x).rbegin(), (x).rend()
#define sz(x)           (ll)x.size()
#define fast_io()       ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
// #define int          long long

// Aliases
using ll =              long long;
using ull =             unsigned long long;
using ld =              long double;
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Constants
constexpr ll INF =      2e18;
constexpr ld EPS =      1e-9;
constexpr ll MOD =      1000000007;
constexpr ll MOD2 =     998244353;
constexpr char nl =     '\n';

typedef vector<int>     vi;
typedef vector<ll>      vll;
typedef pair<int, int>  pii;
typedef pair<ll, ll>    pll;

void init_code() {
    fast_io();
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
#endif
}

struct custom_hash { static uint64_t splitmix64(uint64_t x) { x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); } size_t operator()(uint64_t x) const { static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM); } };
unordered_map<long long, int, custom_hash> u_map;

void _print(ll t)       {cerr << t;}
void _print(int t)      {cerr << t;}
void _print(string t)   {cerr << t;}
void _print(char t)     {cerr << t;}
void _print(ld t)       {cerr << t;}
void _print(double t)   {cerr << t;}
void _print(ull t)      {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

const ll sz = 1e6 + 1;
ll fact[sz], invFact[sz];

ll binExpIter(ll a, ll b) { ll temp = 1; while (b > 0) { if (b & 1) temp = (temp * 1LL * a) % MOD; a  = (a * 1LL * a) % MOD; b >>= 1; } return temp % MOD; }
ll inv(ll n) { return binExpIter(n, MOD - 2) % MOD; }
ll nCr(ll n, ll r) { return (((fact[n] * invFact[n - r]) % MOD) * invFact[r]) % MOD; }
bool isPrime(ll n) { for (ll i = 2; i * i <= n; i++) { if (n % i == 0) return false; } return true; }
void preCompute() { fact[0] = 1, invFact[0] = 1; for (int i = 1; i <= 1e6; i++) { fact[i] = (fact[i - 1] * i) % MOD; invFact[i] = inv(fact[i]) % MOD; } }

void solve()
{
    ll i, j, k, n;
    ll ans, cnt, temp, res;
    
}

int32_t main()
{
    init_code();
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";
    return 0;
}
// max value of min element or vice versa --> BINARY SEARCH ON temp
// try to check whether you can make a checker function or not
// IF USE OF LEAST / MIN  ANYWHERE IN THE STATEMENT FIRST THOUGHT SHOULD BE "BINARY SEARCH"
// THINK DP WHENEVER N*M<=1000000 AT MAX
// WRITE DOWN EVERYTHING
// CHECK FOR GCD , LCM APPROACH . HARD TO SPOT
