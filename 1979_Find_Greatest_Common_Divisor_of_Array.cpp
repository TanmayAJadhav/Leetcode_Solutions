// Given an integer array nums, return the greatest common divisor of the smallest number and largest number in nums.
// The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.

// Example 1:
// Input: nums = [2,5,6,9,10]
// Output: 2
// Explanation:
// The smallest number in nums is 2.
// The largest number in nums is 10.
// The greatest common divisor of 2 and 10 is 2.

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int min = nums[0], max = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            if(max < nums[i])
            {
                max = nums[i];
            }
            if(min > nums[i])
            {
                min = nums[i];
            }
        }
        return __gcd(max,min);
    }
};