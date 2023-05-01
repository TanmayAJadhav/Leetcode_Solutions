// You are given an array of words where each word consists of lowercase English letters.wordA is a predecessor of wordB if and only if we can insert exactly one 
// letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.For example, "abc" is a predecessor of "abac", while "cba" 
// is not a predecessor of "bcad".A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a 
// predecessor of word3, and so on. A single word is trivially a word chain with k == 1.
// Return the length of the longest possible word chain with words chosen from the given list of words.

// Example 1:
// Input: words = ["a","b","ba","bca","bda","bdca"]
// Output: 4
// Explanation: One of the longest word chains is ["a","ba","bda","bdca"].

// Example 2:
// Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
// Output: 5
// Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].

// Example 3:
// Input: words = ["abcd","dbqca"]
// Output: 1
// Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
// ["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.
 
// Constraints:
// 1 <= words.length <= 1000
// 1 <= words[i].length <= 16
// words[i] only consists of lowercase English letters.

// Approach 1 : 

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        std::sort(words.begin(), words.end(), [](const std::string& first, const std::string& second)
        {
            return first.size() < second.size();
        });
        
        map<string, int>mp;
        int ans = 0;
        for(auto word : words)
        {
            mp[word] = 1;
            for(int i = 0; i < word.size(); ++i)
            {
                string sub = word.substr(0,i) + word.substr(i+1, word.size());
                if(mp[sub] > 0)
                {
                    mp[word] = max(mp[word], mp[sub]+1);
                }
            }
            ans = max(mp[word], ans);
        }
        return ans;
    }
};


// Approach-2 :
class Solution {
public:
    static bool compare(string &s1, string &s2)
    {
        return s1.size() < s2.size();
    }
    bool check(string &s1, string s2)
    {
        if(s1.size() != s2.size()+1)
        {
            return false;
        }
        int first = 0, second = 0;
        while(first < s1.size())
        {
            if(s1[first] == s2[second])
            {
                first++;
                second++;
            }
            else
            {
                first++;
            }
        }

        if(first == s1.size() && second == s2.size())
        {
            return true;
        }
        return false;
    }

    int longestStrChain(vector<string>& words) 
    {
        sort(words.begin(),words.end(),compare);
        int n = words.size();
        vector<int>dp(n,1);
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int prev_ind = 0; prev_ind < i; prev_ind++)
            {
                if(check(words[i],words[prev_ind]) && dp[i] < 1+dp[prev_ind])
                {
                    dp[i] = 1+dp[prev_ind];
                }
            }
            ans = max(dp[i],ans);
        }   
        
        return ans;    
    }
};
