class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); ++i)
        {
            sort(grid[i].begin(),grid[i].end());
        }

        for(int i = 0; i < grid[0].size(); ++i)
        {
            int maxele = 0;
            for(int j = 0; j < grid.size(); ++j)
            {
                maxele = max(maxele,grid[j][i]);
            }
            ans += maxele;
        }

        return ans;
        
    }
};