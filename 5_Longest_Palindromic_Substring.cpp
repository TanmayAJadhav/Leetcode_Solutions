class Solution {
public:
    string longestPalindrome(string s) {
        int left = 0, right = 0, start = 0, end = 1;
        int n = s.size();
        vector<vector<int>>dp(n, vector<int>(n,0));
        
        for(int i = 0; i < n; ++i)
        {
            dp[i][i] = 1;
        }

        for(int i = 0; i < n-1; ++i)
        {
            if(s[i] == s[i+1])
            {
                dp[i][i+1] = 1;
                start = i, end = 2;
            }
        }
        
        for(int len = 2; len < n; len++)
        {
            for(int i = 0; i < n-len; i++)
            {
                if(dp[i+1][i+len-1] == 1 && s[i] == s[i+len])
                {
                    dp[i][i+len] = 1;
                    start = i, end = len+1;
                }
            }
        }

        return s.substr(start,end);
        
    }
};