class Solution {
public:

    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1), hash(n);
        int ans = 0, lastIndex = 0;
        for(int i = 0; i < n; i++)
        {
            hash[i] = i;
            for(int prev_ind = 0; prev_ind < i; prev_ind++)
            {
                if(nums[i]%nums[prev_ind] == 0 && dp[i] < 1+dp[prev_ind])
                {
                    dp[i] = 1+dp[prev_ind];
                    hash[i] = prev_ind;
                }
            }
            if(ans < dp[i])
            {
                ans = dp[i];
                lastIndex = i;
            }
        }   
        vector<int>temp;
        temp.push_back(nums[lastIndex]);
        while(hash[lastIndex] != lastIndex)
        {
            lastIndex = hash[lastIndex];
            temp.push_back(nums[lastIndex]);
        }


        return temp;
    }
};