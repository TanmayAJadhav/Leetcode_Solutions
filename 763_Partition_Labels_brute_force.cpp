class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,pair<int,int>>mp;
        unordered_map<char,bool>check;
        vector<int>ans;
        for(int i = 0; i < s.size(); ++i)
        {
            if(check[s[i]]==false)
            {
                mp[s[i]].first=i;
                mp[s[i]].second=i;
                check[s[i]]=true;
            }
            else
            {
                mp[s[i]].second=i;
            }
        }

        int lastocc = mp[s[0]].second, firstocc = 0;
        for(int i = 1; i < s.size(); ++i)
        {
            if(mp[s[i]].first < lastocc)
            {
                lastocc = max(lastocc,mp[s[i]].second);
            }
            else
            {

                lastocc = mp[s[i]].second;
                int temp=mp[s[i]].first;
                ans.push_back(temp-firstocc);
                firstocc = mp[s[i]].first;
            }

        }
        ans.push_back(lastocc-firstocc+1);
        return ans;
    }
};