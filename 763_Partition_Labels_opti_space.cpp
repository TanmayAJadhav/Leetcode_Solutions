class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mp;
        vector<int>ans;
        for(int i = 0; i < s.size(); ++i)
        {
            mp[s[i]]=i;
        }

        int maxlast=0,prev=-1;
        for(int i = 0; i < s.size(); ++i)
        {
            maxlast = max(maxlast,mp[s[i]]);
            if(maxlast==i)
            {
                ans.push_back(maxlast-prev);
                prev = maxlast;
            }
        }
        return ans;
    }
};