class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) 
    {
        vector<int>temp = score;
        vector<string>ans(score.size());
        sort(temp.rbegin(),temp.rend());

        unordered_map<int,int>mp;

        for(int i = 0; i < temp.size(); i++)
        {
            mp[temp[i]] = i;
        }

        for(int i = 0; i < score.size(); i++)
        {
            if(mp[score[i]] == 0)
            {
                ans[i] = "Gold Medal";
            }
            else if(mp[score[i]] == 1)
            {
                ans[i] = "Silver Medal";
            }
            else if(mp[score[i]] == 2)
            {
                ans[i] = "Bronze Medal";
            }
            else
            {
                ans[i] = to_string(mp[score[i]]+1);
            }
        }

        return ans;
    }
};