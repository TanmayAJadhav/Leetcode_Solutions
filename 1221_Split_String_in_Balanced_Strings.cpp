// Balanced strings are those that have an equal quantity of 'L' and 'R' characters. Given a balanced string s, split it in the maximum amount
// of balanced strings.Return the maximum amount of split balanced strings.

// Example 1:
// Input: s = "RLRRLLRLRL"
// Output: 4
// Explanation: s can be split into "RL", "RRLL", "RL", "RL", each substring contains same number of 'L' and 'R'.

class Solution {
public:
    int balancedStringSplit(string s)
    {
        int cnt = 0,l = 0,r = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(l > 0 && l == r)
            {
                cnt++;
                l = 0;
                r = 0;
            }
            if(s[i] == 'L')
            {
                l++;
            }
            else if(s[i] == 'R')
            {
                r++;
            }
        }
        if(l > 0 && l == r)
        {
            cnt++;
        }
        return cnt;
    }   
};