class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_map<int,bool>mp;

        for(auto x:nums)
        {
            mp[x] = true;
        }
        while(true)
        {
            if(mp[original] == false)
            {
                break;
            }
            original = original*2;
        }
        return original;
    }
};