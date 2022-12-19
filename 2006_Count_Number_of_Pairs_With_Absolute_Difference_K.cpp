class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int,int>mp;

        for(auto ele:nums)
        {
            ans += mp[ele-k];
            ans += mp[ele+k];
            mp[ele]++;
        }
        
        return ans;
    }
};  