// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
// Example 1:
// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]

// Example 2:
// Input: nums = [1], k = 1
// Output: [1]

// Constraints:
// 1 <= nums.length <= 105
// k is in the range [1, the number of unique elements in the array].
// It is guaranteed that the answer is unique.

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int it:nums)
        {
            mp[it]++;
        }

        priority_queue<pair<int,int>>pq;

        for(auto it:mp)
        {
            pq.push({it.second,it.first});
        }

        while(!pq.empty() && k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
