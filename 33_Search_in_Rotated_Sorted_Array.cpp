class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int low = 0, high = nums.size()-1;
        
        while(low <= high)
        {
            int mid = (low+high)/2;

            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[low] <= nums[mid]) //Step to find sorted part there is definitely one half is sorted
            {
                if(nums[low] <= target && target <= nums[mid]) //Check whether given target in within range of nums[low] and nums[mid]
                {
                    high = mid-1;
                }
                else
                {
                    low = mid+1;
                }
            }
            else
            {
                if(nums[mid] <= target && target <= nums[high])
                {
                    low = mid+1;
                }
                else
                {
                    high = mid-1;
                }
            }
        }    
        return -1;
    }
};