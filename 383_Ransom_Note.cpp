class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>m1;
        // unordered_map<char,int>m2;
        // unordered_set<int>s;
        
        for(char ch : magazine)
        {
            m1[ch]++;
        }
        
        for(char ch : ransomNote)
        {
            if(m1[ch] == 0)
            {
                return false;
            }
            m1[ch]--;
            // s.insert(ch);
        }
        
//         for(auto it:m1)
//         {
//             if(m2[it.first] < it.second)
//             {
//                 return false;
    //             }
    //         }
        
        return true;
    }
};