class Solution {
public:
    vector<vector<int>>dp;
    int helper(int ind, int tar, vector<int>& coins)
    {
        if(ind == 0)
        {
            if(tar%coins[0] == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        if(dp[ind][tar] != -1)
        {
            return dp[ind][tar];
        }

        int nottake = helper(ind-1, tar, coins);
        int take = 0;
        if(tar >= coins[ind])
        {
            take = helper(ind, tar-coins[ind], coins);
        }

        return dp[ind][tar] = take + nottake;
    }

    int change(int amount, vector<int>& coins) 
    {
        int n = coins.size();
        dp.resize(n,vector<int>(amount+1,-1));
        return helper(n-1, amount, coins);    
    }
};