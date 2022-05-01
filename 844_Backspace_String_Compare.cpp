// Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.
// Note that after backspacing an empty text, the text will continue empty.

// Example 1:
// Input: s = "ab#c", t = "ad#c"
// Output: true
// Explanation: Both s and t become "ac".

// Example 2:
// Input: s = "ab##", t = "c#d#"
// Output: true
// Explanation: Both s and t become "".

// Example 3:
// Input: s = "a#c", t = "b"
// Output: false
// Explanation: s becomes "c" while t becomes "b".

// Constraints:
// 1 <= s.length, t.length <= 200
// s and t only contain lowercase letters and '#' characters.

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>st1,st2;
        int i = 0, j = 0;
        
        while((i < s.size()) || (j < t.size()))
        {
            if(i < s.size())
            {
                if((s[i] == '#') && (!st1.empty()))
                {
                    st1.pop();
                }
                else if(s[i] != '#')
                {
                   st1.push(s[i]); 
                }
                i++;
            }
            
            if(j < t.size())
            {
                if((t[j] == '#') && (!st2.empty()))
                {
                    st2.pop();
                }
                else if(t[j] != '#')
                {
                   st2.push(t[j]); 
                }
                j++;
            }
            // cout<<st1.top()<<" "<<st2.top()<<endl;
            // i++;
            // j++;
        }
        
        //cout<<st1 <<" "<<st2 <<endl;

        if(st1 == st2)
        {
            return true;
        }
        else
        {
            return false;
        }
       
    }
};