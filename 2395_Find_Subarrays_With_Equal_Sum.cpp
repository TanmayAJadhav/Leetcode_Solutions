class Solution {
public:
    bool findSubarrays(vector<int>& nums) 
    {
        int n = nums.size();
        unordered_map<int,bool>mp;
        for(int i = 1; i < n; i++)
        {
            int sum = nums[i-1] + nums[i];
            if(mp[sum])
            {
                return true;
            }
            
            mp[sum] = true;
        }
        
        return false;
    }
};