class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        set<string>s1(words.begin(),words.end());
        set<string>s2(words.begin(),words.end());
        
        for(auto word : s1)
        {
            for(int i = 1; i < word.size(); ++i)
            {
                s2.erase(word.substr(i));
            }
        }
        
        int sum = 0;
        for(auto x : s2)
        {
            sum += x.size();
        }
           
        
        return sum+s2.size();
    }
};