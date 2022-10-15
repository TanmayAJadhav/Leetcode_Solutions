class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>map(n+1);
        if(trust.size()==n)
        {
            return -1;
        }
        for(inta i = 0; i < trust.size(); ++i)
        {
            map[trust[i][0]]++;
        }
        int ans =0;
        for(int i = 1; i < (n+1); ++i)
        {
            if(map[i]==0)
            {
                ans= i;
            }
        }
        int cnt = 0;
        for(int i = 0; i < trust.size(); ++i)
        {
            if(ans==trust[i][1])
            {
                cnt++;
            }
        }
        if(cnt==n-1)
        {
            return ans;
        }
        return -1;        
    }
};