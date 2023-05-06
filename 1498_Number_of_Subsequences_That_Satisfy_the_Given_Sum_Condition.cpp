class Solution {
public:
    int binpow(long long a, long long b) 
    {
        if (b == 0)
            return 1;
        long long res = binpow(a, b / 2);
        if (b % 2)
            return (res * res * a)%mod;
        else
            return (res * res);
    }
    int mod = 1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        vector<int> pre = {1};
        for (auto i = 1; i <= nums.size(); ++i)
        {
            pre.push_back((pre.back() << 1) % mod);   
        }
        sort(nums.begin(),nums.end());
        int i = 0, j = nums.size()-1;
        long long int ans = 0;
        while(i <= j)
        {
            if(nums[i] + nums[j] <= target)
            {
                ans = (ans+pre[j-i])%mod;
                i++;
            }
            else
            {
                j--;
            }
        }
        return ans;
        
    }
};