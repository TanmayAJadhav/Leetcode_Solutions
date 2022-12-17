class Solution {
public:
    string replaceDigits(string s) {
        string ans = "";
        for(int i = 1; i < s.size(); i+=2)
        {
            int digit = s[i]-'0';
            s[i] = (s[i-1]+digit);
            // cout<<digit<<" "<<i<<" "<<s[i]<<endl;
        }
        return s;
    }
};