class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& num1, vector<int>& num2, vector<int>& num3) {
        unordered_set<int>s;
        vector<int>ans;
        unordered_map<int,int>mp;

        for(auto x:num1)
        {
            if(s.find(x) == s.end())
            {
                mp[x]++;
                s.insert(x);
            }
        }
        s.clear();

        for(auto x:num2)
        {
            if(s.find(x) == s.end())
            {
                mp[x]++;
                s.insert(x);
            }
        }
        s.clear();

        for(auto x:num3)
        {
            if(s.find(x) == s.end())
            {
                mp[x]++;
                s.insert(x);
            }
        }

        for(auto it:mp)
        {
            if(it.second >= 2)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
        
    }
};