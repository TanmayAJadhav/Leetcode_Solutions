class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) 
    {
        if(k <= 1)
        {
            return 0;
        }
        int prod = 1, r = 0, l = 0, ans = 0, n = nums.size();
        while(r < n)
        {
            prod *= nums[r];
            cout<<prod<<" : "<<r<<endl;
            while(l < n && prod >= k)
            {
                prod /= nums[l];
                l++;
            }
            // cout<<l<<" : "<<r<<endl;
            ans += (r-l+1);
            r++;
        }
        if(ans < 0)
        {
            return 0;
        }    
        return ans;
    }
};