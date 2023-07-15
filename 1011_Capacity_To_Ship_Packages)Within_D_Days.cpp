class Solution {
public:
    int calcdays(vector<int>& weights, int weight)
    {
        int days = 1, totalweight = 0;

        for(int i = 0; i < weights.size(); i++)
        {
            if(totalweight + weights[i] > weight)
            {
                days++;
                totalweight = weights[i];
            }
            else
            {
                totalweight += weights[i];
            }
        }

        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) 
    {
        int max_ele = 0, sum = 0;

        for(int x:weights)
        {
            sum += x;
            max_ele = max(max_ele,x);
        }

        int low = max_ele, high = sum;
        while(low <= high)
        {
            int mid = (low+high)/2;

            if(calcdays(weights,mid) <= days)
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return low;   
    }
};