class Solution {
public:
    vector<long long>dp;
    long long helper(int i, vector<vector<int>>& questions, int n)
    {
        if(i >= n)
        {
            return 0;
        }
        
        if(dp[i] != -1)
        {
            return dp[i];
        }

        long long pick = questions[i][0] + helper(i+questions[i][1]+1,questions,n);
        long long notpick = 0 + helper(i+1,questions,n);

        return dp[i] = max(pick,notpick);
    }

    long long mostPoints(vector<vector<int>>& questions) 
    {
        int n = questions.size();
        dp.resize(n,-1);
        return helper(0,questions,n);
    }
};