void solve()
{
    // using bits to store info
    // Bitmasks
    // intersection in O(1) --> take &
    // eg. 1st and 3rd bit is set
    // max unsigned int(32) or ull(64) --> The limitation otherwise why would you use sets
    // USE WHEN NUMBER IS LESS LIKE < 32 || < 64

    // eg Q
    // we have workers who work on different days find the max common working days b/w any 2
    // https://codeforces.com/blog/entry/73558

    // to set a bit --> mask = {0, 0, 0}
    // mask = (mask | (1 << days)) --> sets the dayth bit

    // __builtin_popcountll to find the number of set bits --> basically O(1) 
    // can say O(log n) but mostly bit operations are very fast so O(1)
}
