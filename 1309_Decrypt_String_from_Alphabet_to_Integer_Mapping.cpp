// You are given a string s formed by digits and '#'. We want to map s to English lowercase characters as follows: Characters ('a' to 'i') are represented by ('1' to '9') respectively.
// Characters ('j' to 'z') are represented by ('10#' to '26#') respectively.Return the string formed after mapping.The test cases are generated so that a unique mapping will always exist.

// Example 1:
// Input: s = "10#11#12"
// Output: "jkab"
// Explanation: "j" -> "10#" , "k" -> "11#" , "a" -> "1" , "b" -> "2".

// Example 2:
// Input: s = "1326#"
// Output: "acz"

class Solution {
public:
    string freqAlphabets(string s) {
        string st = "";
        string ans = "";
        int i;
        char ch;
        int digit;
        for(i = 0; i < s.size()-2; ++i)
        {
            st = "";
            digit = 0;
            if(s[i+2] == '#')
            {
                st = s.substr(i,i+2);
                digit = stoi(st);
                ch = 'a'+digit-1;
                ans.push_back(ch); 
                i += 2;
            }
            else
            {
                digit = s[i]-'0';
                ch = 'a'+digit-1;
                ans.push_back(ch); 
            }
        }
        if(i < s.size() && s[i+1] != '#')
        {
            while(i < s.size())
            {
                digit = s[i]-'0';
                ch = 'a'+digit-1;
                ans.push_back(ch); 
                i++;
            }
        }
        return ans;
    }
};