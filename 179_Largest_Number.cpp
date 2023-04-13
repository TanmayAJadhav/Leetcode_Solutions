class Solution {
public:

    static bool compare(string &a, string &b)
    {
        if(a+b > b+a)
        {
            return true;
        }
        return false;
    }

    string largestNumber(vector<int>& nums) 
    {
        vector<string>temp;
        for(auto num:nums)
        {
            temp.push_back(to_string(num));
        }

        sort(temp.begin(),temp.end(),compare);

        string ans = "";

        for(auto it:temp)
        {
            ans.append(it);
        }
        int i = 0;
        while(i < ans.size()-1 && ans[i] == '0')
        {
            i++;
        }
        return ans.substr(i);

    }
};