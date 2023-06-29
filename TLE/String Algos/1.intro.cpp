/* 
  - Longest prefix suffix (LPS)
    - eg. a b c d a b d a b c d e
          0 0 0 0 1 2 0 1 2 3 4 0 
    
    - eg. a a a a a a b c a a 
          0 1 2 3 4 5 0 0 1 2

    - eg. a a b a a c a a d a a b a a b a
          0 1 0 1 2 0 1 2 0 2 2 3 4 5 3 4
*/
vector<int> longestPrefixSuffix(string s) {
    int n = s.size();
    vector<int> lps(n, 0);
    int i = 1;
    int len = 0; // the pointer which gets reset
    while (i < n) {
        if (s[i] == s[len]) {
            lps[i] = len + 1;
            len++;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

void solve() {
    string s;
    cin >> s;
    vector<int> lps = longestPrefixSuffix(s);
    for (auto it : lps) cout << it << " ";
    cout << "\n";
}
