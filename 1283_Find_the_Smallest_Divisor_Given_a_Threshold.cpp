class Solution {
public:

    int cal(int mid, vector<int>& nums)
    {
        int total = 0;

        for(auto x: nums)
        {
            total += ceil((double)x/mid);
        }

        return total;
    }

    int smallestDivisor(vector<int>& nums, int threshold) 
    {
        int low = 1, high = *max_element(nums.begin(),nums.end());

        while(low <= high)
        {
            int mid = (high+low)/2;

            if(cal(mid,nums) <= threshold)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }     
        return low;
    }
};