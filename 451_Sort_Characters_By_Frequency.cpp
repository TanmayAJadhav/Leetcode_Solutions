class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(auto c:s)
        {
            mp[c]++;
        }
        priority_queue<pair<int,char>>pq;

        for(auto it:mp)
        {
            pq.push({it.second,it.first});
        }

        string ans = "";
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            string str(it.first,it.second);
            ans += str;
        }
        return ans;
    }
};