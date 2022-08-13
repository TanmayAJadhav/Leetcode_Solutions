class Solution {
private:
    vector<vector<int>>ans;
    vector<int>ds;
public:
    
    void helper(vector<int>& nums, int index, int n)
    {
        if(index == n)
        {
            ans.push_back(ds);
            return;
        }
        
        ds.push_back(nums[index]);
        helper(nums, index+1, n);
        ds.pop_back();
        helper(nums, index+1, n);
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        helper(nums,0,nums.size());
        return ans;
    }
};