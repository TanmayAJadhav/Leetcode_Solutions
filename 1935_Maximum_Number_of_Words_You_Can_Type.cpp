class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_map<char,bool>mp;
        for(char c:brokenLetters)
        {
            mp[c] = true;
        }
        int ans = 0;
        for(int i = 0; i < text.size(); ++i)
        {
            bool flag = true;
            while(text[i] != ' ' && i < text.size())
            {
                if(mp[text[i]] == true)
                {
                    flag = false;
                }
                i++;
            }
            if(flag == true)
            {
                ans++;
            }
        }
        return ans;
    }
};