class Solution {
public:
    int percentageLetter(string s, char letter) {
        unordered_map<char,int>mp;
        int ans = 0;
        for(auto x:s)
        {
            if(x==letter)
            {
                ans++;
            }
        }
        ans=((double)ans/(double)s.length())*100;
        return ans;
    }
};