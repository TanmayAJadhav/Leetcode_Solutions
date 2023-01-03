class Solution {
public:
    int minDeletionSize(vector<string>& strs)
    {
        int cnt = 0;
    
        for(int i = 0; i < strs[0].size(); ++i)
        {
            for(int j = 0; j < strs.size()-1; ++j)
            {   
                // cout<<strs[j][i]<<" "<<strs[j+1][j]<<endl;
                if(strs[j][i] > strs[j+1][i])
                {
                    cnt++;
                    break;
                }
            }
            cout<<endl;
        }
        return cnt;
    }
};