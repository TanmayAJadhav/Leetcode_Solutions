class Solution {
public:
    vector<int>dp;

    int helper(int ind)
    {
        if(ind == 0 || ind == 1)
        {
            return 1;
        }
        
        if(dp[ind] != -1)
        {
            return dp[ind];
        }

        int left = helper(ind-1);
        int right = helper(ind-2);

        return dp[ind] = left+right;
    }

    int climbStairs(int n) {
        dp.resize(n+1,-1);
        return helper(n);
    }
};