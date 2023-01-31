class Solution {
public:
    int maximumValue(vector<string>& str) {
        int ans = 0;
        for(int i = 0; i < str.size(); ++i)
        {
            string temp = str[i];
            bool digit = false;
            bool alpha = false;
            for(int j = 0; j < str[i].size(); ++j)
            {
                if(str[i][j] >= 'a' && str[i][j] <= 'z')
                {
                    alpha = true;
                }
                else
                {
                    digit = true;
                }
            }
            if(digit == true && alpha == false)
            {
                int dig = stoi(temp);
                ans = max(dig,ans);
            }
            else
            {
                ans = max((int)temp.size(),ans);
            }
        }
        return ans;
    }
};  