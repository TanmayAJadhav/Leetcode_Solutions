class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) 
    {
        int j = 0, i = 0, cost = maxCost, ans = 0;
        while(j < s.size())
        {
            cost -= abs(t[j]-s[j]);
            
            while(cost < 0)
            {
                cost += abs(t[i]-s[i]);
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }    
        return ans;
    }
};