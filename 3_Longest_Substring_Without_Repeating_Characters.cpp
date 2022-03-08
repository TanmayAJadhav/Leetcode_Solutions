// Given a string s, find the length of the longest substring without repeating characters.

// Example 1:
// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> map(256,-1);
        int left = 0, right = 0, len = 0, slen = s.size();

        while(right < slen)
        {
            if(map[s[right]] != -1)
            {
                left = max(map[s[right]]+1, left);
            }
            map[s[right]] = right;
            len = max(right-left+1, len);
            right++;
        }
        return len;
    }
};