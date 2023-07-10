class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        vector<int>hash(26,0);
        vector<int>temp(26,0);
        vector<int>ans;

        if(s.size() < p.size())
            return {};

        int k = p.size();
        for(int i = 0; i < k; i++)
        {
            hash[p[i]-'a']++;
            temp[s[i]-'a']++;
        }

        if(hash==temp)
        {
            ans.push_back(0);
        }
        
        for(int i = k; i < s.size(); i++)
        {
            temp[s[i]-'a']++;
            temp[s[i-k]-'a']--;
            if(hash==temp)
            {
                ans.push_back(i-k+1);
            }

        }
        
        return ans;
    }
};