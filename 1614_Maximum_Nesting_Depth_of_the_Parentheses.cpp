class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0, ans = 0;
        for(auto x:s)
        {
            if(x=='(')
            {
                cnt++;
                ans = max(ans,cnt);
            }
            else if(x==')')
            {
                cnt--;
            }
        }
        return ans;
    }
};