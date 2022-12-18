class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        unordered_map<string,bool>mp;
        string str = "";

        for(int i = 0; i < s.size(); ++i)
        {
            str.push_back(s[i]);    
            mp[str] = true;
        }

        for(auto it:mp)
        {
            cout<<it.first<<" :: "<<it.second<<endl;
        }
        int ans = 0;

        for(auto wd:words)
        {
            if(mp[wd] == true)
            {
                ans++;
            }
        }
        return ans;
        
    }
};