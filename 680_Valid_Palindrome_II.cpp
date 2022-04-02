class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.size()-1, cnt1 = 0,cnt2 = 0;
        while(left <= right)
        {
            if(s[left] == s[right])
            {
                left++;
                right--;
            }
            else
            {
                cnt1++;
                left++;
            }
            if(cnt > 1)
            {
                break;
            }
        }
         
        left = 0, right = s.size()-1, cnt1 = 0;
        while(left <= right)
        {
            if(s[left] == s[right])
            {
                left++;
                right--;
            }
            else
            {
                cnt1++;
                right--;
            }
            if(cnt2> 1)
            {
                break;
            }
        }
    
        if(cnt1 <=1 || cnt2<= 1)
        {
            return true;
        }
        
        return false;
    }
};class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.size()-1, cnt1 = 0,cnt2 = 0;
        while(left <= right)
        {
            if(s[left] == s[right])
            {
                left++;
                right--;
            }
            else
            {
                cnt1++;
                left++;
            }
            if(cnt > 1)
            {
                break;
            }
        }
         
        left = 0, right = s.size()-1, cnt1 = 0;
        while(left <= right)
        {
            if(s[left] == s[right])
            {
                left++;
                right--;
            }
            else
            {
                cnt1++;
                right--;
            }
            if(cnt2> 1)
            {
                break;
            }
        }
    
        if(cnt1 <=1 || cnt2<= 1)
        {
            return true;
        }
        
        return false;
    }
};