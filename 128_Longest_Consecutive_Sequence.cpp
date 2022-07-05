class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        for(int i = 0; i < nums.size(); ++i)
        {
            s.insert(nums[i]);
        }
        
        
        int ans = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(s.find(nums[i]-1) == s.end())
            {
                int cnt = 0;
                int curr = nums[i];
                while(s.find(curr) != s.end())
                {
                    cnt++;
                    curr++;
                }
                ans = max(cnt,ans);
            }
        }
        return ans;
    }
};