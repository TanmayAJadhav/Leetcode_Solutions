// You are given two strings of the same length s and t. In one step you can choose any character of t and replace it with another character.Return the minimum number of steps to make t an anagram of s. An Anagram of a string is a string that contains the same characters with a different (or the same) ordering.

// Example 1:
// Input: s = "bab", t = "aba"
// Output: 1
// Explanation: Replace the first 'a' in t with b, t = "bba" which is anagram of s.

// Example 2:
// Input: s = "leetcode", t = "practice"
// Output: 5
// Explanation: Replace 'p', 'r', 'a', 'i' and 'c' from t with proper characters to make t anagram of s.

// Method1
class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int>mp;
        int ans = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            mp[s[i]]++;
            mp[t[i]]--;
        }

        for(auto it:mp)
        {
            ans += abs(it.second);
        }
        return ans/2;
    }
};


// Method2
class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int>mp;
        int ans = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            mp[s[i]]++;
        }

        for(auto x:t)
        {
            if(mp[x]==0)
            {
                ans++;
            }
            else
            {
                mp[x]--;
            }
        }
        return ans;
    }
};