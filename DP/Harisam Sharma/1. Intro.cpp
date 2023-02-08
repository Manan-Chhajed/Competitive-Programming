// 1. convince yourself that it is dp
// 2. figure out the state
// 3. base cases
// 4. figure out the transitions

/* 
  https://codeforces.com/problemset/problem/1253/C
  
  Sweets Eating:
  1. Observation: Eat sweets with higher penalty earlier
  2. for a fixed k, i wiil start with kth sweet and go backwards and eat m sweets evveryday
  3. dp[i] = min penalty if we eat i sweets
  
  when at k = i
  on first day, we were taking [i-m+1, i]
  when at k = i+1
  on first day, we are taking [i-m+2, i+1]
  
  dp[i+1] = dp[i] + a[i+1] + a[i-m+1] + a[i-2m+1] + ...
  
  prefixS[i] = a[i] + a[i-m] + a[i-2m] + ...
  now, dp[i] = dp[i-1] + prefixS[i];
  
  simple base case dp[0] = 0
*/
