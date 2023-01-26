class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int>mp;
        unordered_map<string,int>mp2;
        int ans = 0;
        
        for(auto x:words1)
        {
            mp[x]++;
        }
        for(auto x:words2)
        {
            mp2[x]++;
        }

        for(auto x:mp)
        {
            if(x.second == 1)
            {
                if(mp2[x.first]==1)
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};