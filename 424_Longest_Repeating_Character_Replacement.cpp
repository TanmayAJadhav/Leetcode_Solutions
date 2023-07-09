// You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.Return the length of the longest substring containing the same letter you can get after performing the above operations.

// Example 1:
// Input: s = "ABAB", k = 2
// Output: 4
// Explanation: Replace the two 'A's with two 'B's or vice versa.

// Example 2:
// Input: s = "AABABBA", k = 1
// Output: 4
// Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
// The substring "BBBB" has the longest repeating letters, which is 4.
// There may exists other ways to achive this answer too.
 
// Constraints:
// 1 <= s.length <= 105
// s consists of only uppercase English letters.
// 0 <= k <= s.length

class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int start = 0, end = 0, n = s.size(), ans = 0;
        vector<int>freq(26);

        for(; end < n; end++)
        {
            freq[s[end]-'A']++;

            while((end - start + 1) - *max_element(freq.begin(),freq.end()) > k)
            {
                freq[s[start]-'A']--;
                start++;
            }

            ans = max(ans,end-start+1);
        }
        return ans;

    }
};