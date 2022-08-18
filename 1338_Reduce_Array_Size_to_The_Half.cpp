class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        priority_queue<int>maxheap;
        unordered_map<int,int>mp;
        for(int x : arr)
        {
            mp[x]++;
        }
        
        for(auto it : mp)
        {
            maxheap.push(it.second);
        }
        
        int num = 0,cnt = 0;
        while(!maxheap.empty())
        {
            num += maxheap.top();
            cnt++;
            maxheap.pop();
            if(num >= (arr.size())/2)
            {
                return cnt;
            }
        }
        return cnt;   
    }
};