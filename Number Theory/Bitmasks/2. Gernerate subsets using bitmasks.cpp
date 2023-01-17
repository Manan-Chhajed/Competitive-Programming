// representing subset using bits as bitmasks
// eg. array 2 3 7 8 9
// as subset [3, 8] --> 0 0 0 0 0 array size
//                  --> 0 1 0 1 0 represents the subset where 1st and 3rd elements of an array are present

// Finding subsets
// eg. 2 4 5        n = 3
// so 0 to 2^n-1 --> all the subsets
// here 0 to 7 represents all the subsets

// leetcode q to print all subsets
vector<vector<int>> subsets(vector<int>& nums) 
    {
        int n = nums.size();
        int subset_cnt = (1 << n);

        vector<vector<int>> subsets;
        for(int mask=0; mask<=subset_cnt-1; ++mask)
        {
            vector<int> subset;
            for(int i=0; i<n; i++)
            {
                if((mask & (1 << i)) != 0)
                {
                    subset.push_back(nums[i]); 
                }
            }
            subsets.push_back(subset);
        }
        return subsets;
    }
