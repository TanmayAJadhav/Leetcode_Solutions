class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int temp = 0, even, odd;
        for(odd = 0, even = 0; odd < nums.size(); odd++)
        {
            if(nums[odd] % 2)
            {
                continue;
            }
            if(odd != even)
            {
                temp = nums[even];
                nums[even] = nums[odd];
                nums[odd] = temp;
            }
            even++;
        }
        return nums;
    }
};