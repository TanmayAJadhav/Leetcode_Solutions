class Solution {
public:
    vector<vector<int>>dp;
    int helper(int i, int allowbuy, vector<int>& prices)
    {
        if(i>=prices.size())
        {
            return 0;
        }
        if(dp[i][allowbuy] != -1)
        {
            return dp[i][allowbuy];
        }
        int profit = 0;
        if(allowbuy)
        {
            profit = max(-prices[i] + helper(i+1,0,prices),0+helper(i+1,1,prices));
        }
        else
        {
            profit = max(prices[i] + helper(i+2,1,prices), 0 + helper(i+1,0,prices));
        }
        return dp[i][allowbuy] = profit;
    }

    int maxProfit(vector<int>& prices) 
    {
        dp.resize(prices.size(),vector<int>(2,-1));
        return helper(0,1,prices);  309. Best Time to Buy and Sell Stock with Cooldown
    }
};