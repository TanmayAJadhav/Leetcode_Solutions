class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        vector<vector<int>>ans(n, vector<int>(n));
        for(int i = 0; i < n; ++i)
        {
            int k = n-1;
            for(int j = 0; j < n; ++j)
            {
                if(image[i][k]==0)
                {
                    ans[i][j] = 1;
                }
                else
                {
                    ans[i][j] = 0;
                }
                k--;

            }
        }
        return ans;
    }
};