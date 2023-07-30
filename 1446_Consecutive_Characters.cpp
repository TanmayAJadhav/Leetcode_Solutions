class Solution {
public:
    int maxPower(string s) 
    {
        
        int cnt = 0, ans = 0, flag = false;
        for(int i = 0; i < s.size()-1; i++)
        {
            if(s[i] == s[i+1])
            {
                cnt++;
            }
            else
            {
                flag = true;
                cnt = 1;
            }
            ans = max(ans,cnt);
        }    
        if(flag==false)
        {
            return ans+1;
        }
        return ans;
    }
};