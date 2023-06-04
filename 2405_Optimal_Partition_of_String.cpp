class Solution {
public:
    int partitionString(string s) 
    {
        unordered_map<char,bool>mp;
        int ans = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(mp[s[i]] == false)
            {
                mp[s[i]] = true;
            }
            else
            {
                ans++;
                mp.clear();
                mp[s[i]] = true;
            }
        }

        return ans+1;
    }
};