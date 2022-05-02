// Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.
// Return any array that satisfies this condition.

// Example 1:
// Input: nums = [3,1,2,4]
// Output: [2,4,3,1]
// Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.

// Example 2:
// Input: nums = [0]
// Output: [0]

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0, j = nums.size()-1, temp = 0;
        while(i < j)
        {
            if((nums[i] & 1) && ((nums[j] & 1) == 0))
            {
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
            if((nums[i] & 1) == 0)
            {
                i++;
            }
            if(nums[j] & 1)
            {
                j--;
            }
        }
                
        return nums;
    }
};