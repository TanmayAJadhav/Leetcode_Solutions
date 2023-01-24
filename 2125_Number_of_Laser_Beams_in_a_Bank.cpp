class Solution {
public:
    int numberOfBeams(vector<string>& bank) {

        int cnt1 = 0,cnt2=0;
        for(int  i = 0; i < bank[0].size(); ++i)
        {
            if(bank[0][i]=='1')
            {
                cnt1++;
            }
        }

        int ans = 0;
        for(int i = 0; i < bank.size()-1; ++i)
        {
            cnt2 = 0;
            for(int j = 0; j < bank[0].size(); ++j)
            {
                if(bank[i+1][j]=='1')
                {
                    cnt2++;
                }
            }

            if(cnt2!=0)
            {
                ans += cnt1*cnt2;
                cnt1 = cnt2;
            }

        }
        return ans;
    }
};