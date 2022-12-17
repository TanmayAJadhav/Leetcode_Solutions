class Solution {
public:
    string sortSentence(string s) {
        map<int,string>mp;
        string ans = "";
        int i = 0;
        while(i < s.size())
        {
            string str = "";
            while(s[i] < '1' || s[i] > '9')
            {
                str += s[i];
                i++;
            }
            int ind = s[i]-'0';
            mp[ind] = str;
            i+=2;
        }
        for(auto st:mp)
        {
            ans += st.second;
            if(st.first >= mp.size())
            {
                break;
            }
            ans += " ";
        }
        cout<<ans;
        return ans;

    }
};