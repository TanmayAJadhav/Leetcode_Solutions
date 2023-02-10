class Solution {
public:
    string customSortString(string order, string s) 
    {
        unordered_map<char,bool>ordermap;
        unordered_map<char,pair<int,bool>>smap;

        for(int i = 0; i < s.size(); ++i)
        {
            smap[s[i]].first += 1;
            smap[s[i]].second = true;
        } 
        for(int i = 0; i < order.size(); ++i)
        {
            ordermap[order[i]] = true;
        } 

        string first = "", second = "";
        
        for(int i = 0; i < s.size(); ++i)
        {
            if(ordermap.find(s[i]) == ordermap.end())
            {
                second.push_back(s[i]);
            }
        }

        for(int i = 0; i < order.size(); ++i)
        {
            if(smap[order[i]].second==true)
            {
                for(int j = 0; j < smap[order[i]].first; ++j)
                {
                    first.push_back(order[i]);
                }
            }
        }

        first += second;
       
        return first;
    }
};