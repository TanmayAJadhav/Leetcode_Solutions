class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>dp(n,1), cnt(n,1);
        int ans = 0;
        for(int currind = 0; currind < n; currind++)
        {
            for(int prev_ind = 0; prev_ind < currind; prev_ind++)
            {
                if(nums[currind] > nums[prev_ind] && 1+ dp[prev_ind] > dp[currind])
                {
                    dp[currind] = 1+ dp[prev_ind];
                    cnt[currind] = cnt[prev_ind];
                }
                else if(1+ dp[prev_ind] == dp[currind])
                {
                    cnt[currind] += cnt[prev_ind];
                }
            }
            if(dp[currind] > ans)
            {
                ans = dp[currind];
            }
        } 

        
        int final_ans = 0;

        for(int i = 0; i < n; i++)
        {
            if(ans==dp[i])
            {
                final_ans += cnt[i];
            }
        }
        return final_ans;
    }
};