class Solution {
public:
    int minMoves2(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());
        
        int n = nums.size();
        int middle = nums[n/2], ans = 0;
            
        for(int num : nums)
        {
            ans += abs(num-middle);
        }
        return ans;
    }
};