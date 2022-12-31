class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int ans = 0, n = travel.size();
        vector<int>pre(n);
        pre[0] = travel[0];
        for(int i = 1; i < n; ++i)
        {
            pre[i] = pre[i-1]+travel[i];
        }
        int lm = 0, lp = 0, lg = 0;
        for(int i = 0; i < garbage.size(); ++i)
        {
            string s = garbage[i];
            ans += s.size();
            for(int j = 0; j < s.size(); ++j)
            {
                if(s[j]=='M')
                {
                    lm = i;
                }
                else if(s[j]=='G')
                {
                    lg = i;
                }
                else if(s[j]=='P')
                {
                    lp = i;
                }
            }
        }
        if(lm)
        {
            ans += pre[lm-1];
        }
        if(lg)
        {
            ans += pre[lg-1];
        }
        if(lp)
        {
            ans += pre[lp-1];
        }
        return ans;
    }
};