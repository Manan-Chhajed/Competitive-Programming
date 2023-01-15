Quite easy
1. sort pair<int ,int> with <number, index>
2. ans = 0, cnt = 0
3. traverse, if v[i].S > v[i-1].S then cnt++
4. else ans -= cnt and cnt = 0;
5. in the end, ans -= cnt
