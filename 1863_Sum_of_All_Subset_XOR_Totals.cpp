class Solution {
public:
    int ans;
    void helper(int ind, vector<int>& nums, int xorr)
    {
        if(ind == -1)
        {
            ans += xorr;
            return;
        }

        helper(ind-1,nums,xorr ^ nums[ind]);
        helper(ind-1,nums,xorr); 
    }

    int subsetXORSum(vector<int>& nums) 
    {
        ans = 0;
        helper(nums.size()-1,nums,0);  
        return ans;  
    }
};
