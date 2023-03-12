class Solution {
public:
    string greatestLetter(string s) {
        vector<bool>v1(26,0); 
        vector<bool>v2(26,0);
        for(int i=0;i<s.size();i++)
        {
            if(s[i] >= 'a' &&  s[i] <= 'z')
            {
                v2[s[i]-'a'] = true;   
            }
            else if(s[i] >= 'A' &&  s[i] <= 'Z')
            {
                v1[s[i]-'A'] = true;
            }
        }

        string ans;
        for(int i=25;i>=0;i--)
        {
            if(v1[i]>0 && v2[i]>0)
            {
                ans.push_back(i+'A'); 
                break;
            }
        }

        return ans;
    }
};