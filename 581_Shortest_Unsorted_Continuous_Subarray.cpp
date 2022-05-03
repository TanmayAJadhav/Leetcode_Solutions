// Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.
// Return the shortest such subarray and output its length.

// Example 1:
// Input: nums = [2,6,4,8,10,9,15]
// Output: 5
// Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.

// Example 2:
// Input: nums = [1,2,3,4]
// Output: 0

// Example 3:
// Input: nums = [1]
// Output: 0

// Constraints:
// 1 <= nums.length <= 104
// -105 <= nums[i] <= 105

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int min = nums[nums.size()-1], max = nums[0];
        int start = 0,end = -1;
        int i, j;
        for(i = 1,j  = nums.size()-2; i < nums.size(), j >= 0; i++, j--)
        {   
            // cout<<start<<" "<<end<<endl;
            if(max <= nums[i])
            {
                max = nums[i];
            }
            else
            {
                end = i;
            }
            if(min >= nums[j])
            {
                min = nums[j];
            }
            else
            {
                start = j;
            }
        }
        return end-start+1;
    }
};