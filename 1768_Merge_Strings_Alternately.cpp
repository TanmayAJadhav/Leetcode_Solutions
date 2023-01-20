class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        int minsize = max(word1.size(),word2.size());
        int i;
        for(i = 0; i < minsize; ++i)
        {
            if(i < word1.size())
            {
                ans.push_back(word1[i]);
            }
            if(i < word2.size())
            {
                ans.push_back(word2[i]);
            }
        }

        for(; i < word1.size(); ++i)
        {
            ans.push_back(word1[i]);
        }
        
        for(; i < word2.size(); ++i)
        {
            ans.push_back(word2[i]);
        }
        return ans;
    }
};