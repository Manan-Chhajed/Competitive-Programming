// (a/b) % M == (a * b^-1) % M
//             == ((a%M) * (b^-1 % M)) % M

// b^-1 % M --> Modular Multiplicative inverse of b

/* 
  a*b == 1
  then b is multiplicative inverse of a
  
  similarly, (a*b)%M == 1
  b is MMI of a
  1 <= b <= M-1
  (a%M * b%M)%M == 1
  loop b = 1 to M-1 to find MMI of a --> O(1)
  
  MMI is defined only if a and b are coprime                        else it gets complicated
  
  FERMAT'S THEOREM
  Congruency of Numbers --> A^(M-1) % M = 1 where M is prime and A is not a multiple of M
  mulitply both sides by A^-1
  (A^(M - 2)) % M == A^-1
  
  // to declare a global array
  const int N = 1e5 + 1;
  int globalArray[N];
*/
