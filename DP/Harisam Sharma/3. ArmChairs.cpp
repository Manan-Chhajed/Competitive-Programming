// https://codeforces.com/problemset/problem/1525/D

/* 
  constraints are low --> dp --> quadratic works
  
  v1 --> all indices which are initally occupied
  v2 --> all indices which are intially free
  size of v2 >= v1
  
  STATE OF THE DP
  dp[i][j] --> It is the min time needed if I start at pos i in v1 and pos j in v2
  
  final ans --> dp[0][0]
  
  1. dp[i][j] --> dp[i+1][j+1]         when I move i(in v1) to j(in v2)
  which is equal to dp[i][j] = abs(v[i] - v2[j]) + dp[i+1][j+1]
  2. dp[i][j] --> dp[i][j+1]
  
*/
