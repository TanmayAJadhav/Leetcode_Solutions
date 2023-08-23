class Solution {
public:
    string reorganizeString(string s) 
    {
        priority_queue<pair<int,int>>pq;
        unordered_map<char,int>mp;
        int ele = 0;
        for(char c:s)
        {
            mp[c]++;
            ele = max(ele,mp[c]);
        }    
        if(ele > s.size())
        {
            return "";
        }
        for(auto it:mp)
        {
            pq.push({it.second,it.first});
        }
        string ans =  "";
        while(pq.size() >= 2)
        {
            auto it1 = pq.top();
            pq.pop();
            auto it2 = pq.top();
            pq.pop();

            int freq1 = it1.first;
            int freq2 = it2.first;

            ans.push_back(it1.second);
            ans.push_back(it2.second);

            freq1--;
            freq2--;
            if(freq1 > 0)
            {
                pq.push({freq1,it1.second});
            }
            if(freq2 > 0)
            {
                pq.push({freq2,it2.second});
            }
        }

        if(pq.empty()==false)
        {
            if(pq.top().first > 1)
            {
                return "";
            }
            ans.push_back(pq.top().second);
        }
        return ans;
    }
};