// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid. An input string is valid if:
// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
 
// Example 1:
// Input: s = "()"
// Output: true

class Solution {
public:
    bool isValid(string str)
    {
        stack<char> st;
        for(int i = 0; i < str.size(); i++)
        {
            char current = str[i];
            if(current == '(' || current == '[' || current == '{')
            {
                st.push(current);
            }
            else
            {
                if(!st.empty())
                {
                    char topchar = st.top();
                    if((topchar == '(' && current == ')' ) || (topchar == '{' && current == '}') || (topchar == '[' && current == ']'))
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                }   
                else
                {
                    return false;
                }
            }   
        }
        if(st.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};