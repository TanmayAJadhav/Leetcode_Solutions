class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        int n = nums.size();

        for(int i = 0; i < n; i++)
        {
            if(nums[i] > 0 && nums[i] <= n && nums[nums[i]-1] != nums[i])
            {
                int numatpos = nums[nums[i]-1];
                int temp = nums[i];
                nums[nums[i]-1] = nums[i];
                nums[i] = numatpos;
                i--;
            }
        }

        if(nums[0] == INT_MIN)
        {
            return 1;
        }
        for(int i = 0; i < n; i++)
        {
            if(nums[i]-1 != i)
            {
                return i+1;
            }
        }
        return n+1;
    }
};