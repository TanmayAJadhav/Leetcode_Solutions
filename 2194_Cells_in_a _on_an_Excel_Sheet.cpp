class Solution {
public:
    vector<string> cellsInRange(string s) {
        char leftalpha = s[0], rightalpha = s[3], leftdig = s[1], rightdig = s[4];
        vector<string>ans;
        for(char i = leftalpha; i <= rightalpha; ++i)
        {
            for(char j = leftdig; j <= rightdig; ++j)
            {
                string str;
                str.push_back(i); 
                str.push_back(j);
                ans.push_back(str);
            }
        }
        return ans;
    }
};