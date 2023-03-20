class Solution {
public:
    vector<vector<int>>dp;

    bool helper(int i, int sum, vector<int>& nums)
    {
        if(i == 0)
        {
            return nums[i] == sum;
        }

        if(sum == 0)
        {
            return true;
        }

        if(dp[i][sum] != -1)
        {
            return dp[i][sum];
        }

        bool notTake = helper(i-1, sum, nums);
        bool take = false;
        if(nums[i] <= sum)
        {
            take = helper(i-1, sum-nums[i], nums);
        }

        return dp[i][sum] = take | notTake;
    }

    bool canPartition(vector<int>& nums) 
    {
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
        }   

        if(sum%2)
        {
            return false;
        }
        sum = sum/2;
        dp.resize(n,vector<int>(sum+1,-1));
        return helper(n-1, sum, nums);
    }
};