class Solution {
public:
    vector<vector<int>>dp;
    int helper(vector<vector<int>>& matrix, int i, int j)
    {
        if(j < 0 || j >= matrix.size())
        {
            return 1e9;
        }

        if(i==0)
        {
            return matrix[0][j];
        }

        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int u = matrix[i][j] + helper(matrix,i-1,j);
        int dl = matrix[i][j] + helper(matrix,i-1,j-1);
        int dr = matrix[i][j] + helper(matrix,i-1,j+1);

        return dp[i][j] = min(u,min(dl,dr));
    }

    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        int ans = 1e9;
        dp.resize(matrix.size(),vector<int>(matrix.size(),-1));
        for(int i = 0; i < matrix.size(); i++)
        {
            ans = min(ans,helper(matrix,matrix.size()-1,i));
        }
        return ans;
    }
};