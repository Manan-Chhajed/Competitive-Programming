// https://codeforces.com/problemset/problem/1324/E

/* 
  n and h constraints hint for dp
  
  Sleeping Schedule:
  dp[i][j] --> max no. of good sleeps I can have, if I start fromt the ith sleep and current time is j
  final ans --> dp[1][0]
  
  dp[i][j] --> dp[i+1][j+a[i] % h]
  dp[i][j] --> dp[i+1][j+a[i]-1 % h]
  
  TRANSITIONS
  f1 = 1 if (j+a[i]) % h is between l to r
  else 0
  
  f2 = 1 if(j+a[i]-1) % h is between l to r
  else 0
  
  dp[i][j] = max(f1 + dp[i+1][(j+a[i]) % h], f2 + dp[i+1][(j+a[i]-1) % h]);
*/
