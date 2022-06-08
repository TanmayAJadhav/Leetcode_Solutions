class Solution {
public:
    int removePalindromeSub(string s) {
        int left = 0, right = s.size()-1;
        for(; left < right; ++left,--right)
        {
            if(s[left] != s[right])
            {
                return 2;
            }
        }
        return 1;
    }
};