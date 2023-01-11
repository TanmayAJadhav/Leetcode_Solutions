// You are given an array of strings words and a string pref.Return the number of strings in words that contain pref as a prefix.A prefix of a string s is any leading contiguous substring of s.

// Example 1:
// Input: words = ["pay","attention","practice","attend"], pref = "at"
// Output: 2
// Explanation: The 2 strings that contain "at" as a prefix are: "attention" and "attend".

// Example 2:
// Input: words = ["leetcode","win","loops","success"], pref = "code"
// Output: 0
// Explanation: There are no strings that contain "code" as a prefix.

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt = 0, n = pref.size();
        int j = 0;
        for(int i = 0; i < words.size(); ++i)
        {
            int ind = 0;
            if(words[i].size() < n)
            {
                continue;
            }
            for(j = 0; j < n; ++j)
            {
                if(words[i][j]!=pref[j])
                {
                    break;
                }
                ind++;
            }
            cout<<"hi "<<j<<endl;
            if(j == n)
            {
                cnt++;
            }
        }
        return cnt;
    }
};