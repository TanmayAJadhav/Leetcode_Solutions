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
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        struct node
        {
            int key;
            int val;
            node(int a, int b)
            {
                key = a;
                val = b;
            }
        };
        struct compare
        {
            bool operator()(node const& a, node const& b)
            {
                return a.val > b.val;
            }
        };
        
        map<int, int>mp;
        priority_queue<node, vector<node>, compare> max_heap;
        
        for(int ele : nums)
        {
            mp[ele]++;
        }
        for(auto it : mp)
        {
            max_heap.push(node(it.first,it.second));
            if(max_heap.size() > k)
            {
                max_heap.pop();
            }
        }
        
        while(! max_heap.empty())
        {
            res.push_back(max_heap.top().key);
            max_heap.pop();
        }
        return res;
    }
};