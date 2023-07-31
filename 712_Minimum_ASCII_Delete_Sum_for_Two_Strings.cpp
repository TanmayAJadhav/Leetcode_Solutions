class Solution {
public:
    vector<vector<int>>dp;
    int getSum(string &s, int ind)
    {
        int sum=0;
        for(int i = 0; i < ind; i++)
        {
            sum += s[i];
        }
        return sum;
    }
    int helper(int ind1, int ind2, string &s1, string &s2)
    {
        if(ind1==0)
        {
            return dp[ind1][ind2] = getSum(s2,ind2);
        }

        if(ind2==0)
        {
            return dp[ind1][ind2] = getSum(s1,ind1);
        }

        if(dp[ind1][ind2] != -1)
        {
            return dp[ind1][ind2];
        }

        if(s1[ind1-1]==s2[ind2-1])
        {
            return dp[ind1][ind2] = helper(ind1-1,ind2-1,s1,s2);
        }
        else
        {
            return dp[ind1][ind2] = min(s1[ind1-1] + helper(ind1-1,ind2,s1,s2), s2[ind2-1] + helper(ind1,ind2-1,s1,s2));
        }         
    }

    int minimumDeleteSum(string s1, string s2) 
    {
        dp.resize(s1.size()+1,vector<int>(s2.size()+1,-1));
        return helper(s1.size(),s2.size(),s1,s2);    
    }
};