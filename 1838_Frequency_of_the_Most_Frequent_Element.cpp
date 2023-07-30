class Solution {
public:

    bool possible(vector<int>& nums, int mid, int k)
    {
        long long int windowSum = 0;

        for(int i = 0; i < mid; i++)
        {
            windowSum += nums[i];
        }
        
        long long int total = (long long) nums[mid-1]*mid;

        if(total - windowSum <= k)
        {
            return true;
        }

        int i = mid,j = 0;

        while(i < nums.size())
        {
            windowSum -= nums[j];
            windowSum += nums[i];

            total = (long long) nums[i]*mid;

            if(total - windowSum <= k)
            {
                return true;
            }
            i++;
            j++;
        }
        return false;
        
    }

    int maxFrequency(vector<int>& nums, int k) 
    {
        int left = 1, right = nums.size();
        int ans = 0;
        sort(nums.begin(),nums.end());
        while(left <= right)
        {
            int mid = left + (right-left)/2;
            if(possible(nums,mid,k))
            {
                ans = mid;
                left = mid+1;
            }
            else
            {
                right = mid-1;
            }
        }
        return ans;
    }
};1838. Frequency of the Most Frequent Element
