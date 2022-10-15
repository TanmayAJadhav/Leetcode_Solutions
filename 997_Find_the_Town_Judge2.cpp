class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>map(n+1);
        for(int i = 0; i < trust.size(); ++i)
        {
            map[trust[i][1]]++;
            map[trust[i][0]]--;
        }        
        // int ans = 0;
        for(int i = 1; i < (n+1); ++i)
        {
            if(map[i]==(n-1))
            {
                return i;
            }
        }
        
        return -1;
    }
};