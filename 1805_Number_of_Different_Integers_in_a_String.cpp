class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_map<string,int>s;
        for(int i = 0; i < word.size(); ++i)
        {
            if(word[i] >= '0' && word[i] <= '9')
            {
                string str = "";
                while (word[i] == '0')
                {
                    i++;
                }
                while(word[i] >= '0' && word[i] <= '9')
                {
                    str += word[i];
                    i++;
                }
                
                s[str] = 1;
            }
        }
        
        return s.size();
    }
};