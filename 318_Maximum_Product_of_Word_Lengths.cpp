// Given a string array words, return the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. 
// If no such two words exist, return 0.

// Example 1:
// Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
// Output: 16
// Explanation: The two words can be "abcw", "xtfn".

// Example 2:
// Input: words = ["a","ab","abc","d","cd","bcd","abcd"]
// Output: 4
// Explanation: The two words can be "ab", "cd".

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int statelevel[words.size()];
        
        for(int i = 0; i < words.size(); i++)
        {
            int state = 0;
            for(auto ch : words[i])
            {
                int index = ch - 'a';
                state = (state) | 1 << (index);
            }
            statelevel[i] = state;
        }
        unsigned long int maxans = 0;
        for(int i = 0; i < words.size(); i++)
        {
            for(int j = i+1; j < words.size(); j++)
            {
                if((statelevel[i] & statelevel[j]) == 0)
                {
                    maxans = max((words[i].size()*words[j].size()), maxans);
                }
            }
        }
        
        return maxans;
        
    }
};