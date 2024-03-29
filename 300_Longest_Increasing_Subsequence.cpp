class Solution {
public:
    vector<vector<int>>dp;
    int helper(int ind, int prev_ind, vector<int>& nums)
    {
        if(ind ==  nums.size())
        {
            return 0;
        }

        if(dp[ind][prev_ind+1] != -1)
        {
            return dp[ind][prev_ind+1];
        }

        int nottake = helper(ind+1,prev_ind,nums);
        int take = 0;
        if(prev_ind == -1 || nums[ind] > nums[prev_ind])
        {
            take = 1 + helper(ind+1,ind,nums);
        }

        return dp[ind][prev_ind+1] = max(take,nottake);
    }

    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        // dp.resize(n,vector<int>(n+1,-1));
        // return helper(0,-1,nums);   

        vector<int>dp(n,1), hash(n);
        int ans = 0, lastIndex = 0;
        for(int currind = 0; currind < n; currind++)
        {
            hash[currind] = currind;
            for(int prev_ind = 0; prev_ind < currind; prev_ind++)
            {
                if(nums[currind] > nums[prev_ind] && 1+ dp[prev_ind] > dp[currind])
                {
                    dp[currind] = 1+ dp[prev_ind];
                    hash[currind] = prev_ind;
                }
            }
            if(dp[currind] > ans)
            {
                ans = dp[currind];
                lastIndex = currind;
            }
        } 
        vector<int>temp;

        while(hash[lastIndex] != lastIndex)
        {
            lastIndex = hash[lastIndex];
            temp.push_back(nums[lastIndex]);
        }   

        reverse(temp.begin(), temp.end());

        for(auto it:temp)
        {
            cout<<it<<" ";
        }
        cout<<endl;
        return ans;
    }
};
