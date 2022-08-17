class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....",
                  "..",".---","-.-",".-..","--","-.","---",".--.",
                  "--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string>s;
        
        for(string word : words)
        {
            string temp = "";
            for(auto ch : word)
            {
                temp += morse[ch-'a'];
            }
            s.insert(temp);
        }
        
        return s.size();
    }
};