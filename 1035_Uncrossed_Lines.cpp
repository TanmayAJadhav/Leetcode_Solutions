class Solution {
public: 
    vector<vector<int>>dp;
    int helper(int i, int j, int n1, int n2, vector<int>& nums1, vector<int>& nums2)
    {
        if(i == n1 || j == n2)
        {
            return 0;
        }       

        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if(nums1[i] == nums2[j])
        {
            return dp[i][j] = 1 + helper(i+1,j+1,n1,n2,nums1,nums2);
        }
        else
        {
            return dp[i][j] = max(helper(i+1,j,n1,n2,nums1,nums2),helper(i,j+1,n1,n2,nums1,nums2));
        }
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) 
    {
        dp.resize(nums1.size(),vector<int>(nums2.size(),-1));
        return helper(0,0, nums1.size(), nums2.size(), nums1, nums2);
    }
};