class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) 
    {
        // sort(arr.begin(),arr.end());
        // int diff = arr[1] - arr[0];
        // for(int i = 1; i < arr.size()-1; i++)
        // {
        //     if(arr[i+1]-arr[i]!=diff)
        //     {
        //         return false;
        //     }
        // }    
        // return true;

        int minval = INT_MAX;
        int maxval = INT_MIN;
        int n = arr.size();
        unordered_map<int,bool>mp;

        for(int num : arr)
        {
            minval = min(minval,num);
            maxval = max(maxval,num);
            mp[num] = true;
        }
        
        int diff = maxval - minval;

        if((diff)%(n-1))
        {
            return false;
        }

        diff = diff/(n-1);

        for(int i = 0; i < n; i++)
        {
            if(mp[minval] == false)
            {
                return false;
            }

            minval += diff;
        }

        return true;
    }
};