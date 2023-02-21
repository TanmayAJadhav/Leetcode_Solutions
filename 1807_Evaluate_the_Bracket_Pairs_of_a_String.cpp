class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mp;
        for(int i = 0; i < knowledge.size(); ++i)
        {
            mp[knowledge[i][0]] = knowledge[i][1];
        }

        string ans = "";
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i]=='(')
            {
                // cout<<"start "<<i<<" ";
                string st = "";
                i++;
                while(s[i] != ')')
                {
                    st.push_back(s[i]);
                    i++;
                }
                // i++;
                if(mp.find(st) != mp.end())
                {
                    ans += mp[st];
                }
                else
                {
                    ans += '?';
                }
                // cout<<"end "<<i<<" \n";
                if(i >= s.size())
                {
                    break;
                }
            }
            if(s[i] != ')')
            {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};