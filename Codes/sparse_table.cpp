/* 
  - Prefix sum doesn't work for non invertible operations
  - Sparse table works for invertible operations as well
    - Invertible means say you know answer for [1, 10] and [1, 15], can you find [10, 15]
  - What if operation is idempotent?
    - say you want answer for query 1 to 7, you can calculate for say 1 to 4(no. smaller than 7 that is a multiple of 2)
    - then you can find for 1 to 4 and any range such that you reach end of query array (i.e. reach 7)
    - so you can choose 1 to 4 and 3 to 7, since idempotent, overlap of the segment is fine
    - Idempotent means say f(x, x) = x, e.g. min, max, gcd, bitwise and, bitwise or
    - TC --> O(1 * op) for 1 query
    - Here op is the time for that particular query, say op for min is O(1) but for gcd is O(a) where a is larger of the 2 numbers
    - But still preprocessing of O(nlogn)
*/
