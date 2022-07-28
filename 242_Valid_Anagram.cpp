// Given two strings s and t, return true if t is an anagram of s, and false otherwise.An Anagram is a word or phrase formed by rearranging the letters of a
// different word or phrase, typically using all the original letters exactly once.

// Example 1:
// Input: s = "anagram", t = "nagaram"
// Output: true

// Example 2:
// Input: s = "rat", t = "car"
// Output: false

// Constraints:
// 1 <= s.length, t.length <= 5 * 104
// s and t consist of lowercase English letters.

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int n1 = s.size(), n2 = t.size();
        if (n1 != n2)
        {
            return false;
        }

        map<char, int> m;

        for (int i = 0; i < n1; ++i)
        {
            m[s[i]]++;
            m[t[i]]--;
        }

        for (auto it : m)
        {
            if (it.second != 0)
            {
                return false;
            }
        }
        return true;
    }
};