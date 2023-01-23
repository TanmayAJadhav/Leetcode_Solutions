class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int>ans;
        int cnt = 0, i = 0;
        for(; i < s.size(); ++i)
        {
            if(s[i]==c)
            {
                break;
            }
        }
        int j;
        for(j = i; j >=0; j--)
        {
            ans.push_back(j);
        }
        int k=0,l=0;
        for(k=i+1; k < s.size(); ++k)
        {
            if(s[k]==c)
            {
                for(l = i+1; l <= k; l++)
                {
                    int temp = min(l-i,k-l);
                    ans.push_back(temp);
                }
                i = k;
            }
        }
        
        if(i<s.size()-1)
        {
            int cnt=1;
            for(l=i; l < s.size()-1;++l)
            {
                ans.push_back(cnt);
                cnt++;
            }

        }
        return ans;

    }
};