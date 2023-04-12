class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string ans = "";
        for(int i = 0; i < strs[0].size(); i++)
        {
            char ch = strs[0][i];
            int j = 1;
            for(; j < n; j++)
            {
                if(i < strs[j].size())
                {
                    if(ch != strs[j][i])
                    {
                        return ans;
                    }
                }
                else
                {
                    return ans;
                }
            }
            ans.push_back(ch);
        }
        return ans;
    }
};