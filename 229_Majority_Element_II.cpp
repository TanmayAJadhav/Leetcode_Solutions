// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

// Example 1:
// Input: nums = [3,2,3]
// Output: [3]

// Example 2:
// Input: nums = [1]
// Output: [1]

// Example 3:
// Input: nums = [1,2]
// Output: [1,2]

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int> mp;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        for (auto num : mp)
        {
            if (num.second > nums.size()/3)
            {
               res.push_back(num.first);
            }
        }
        return res;
    }
};