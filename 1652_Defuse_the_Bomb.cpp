class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int>ans(n,0);
        bool flag = false;
        if(k == 0)
        {
            return ans;
        }
        else if(k < 0)
        {
            reverse(code.begin(),code.end());  
            k = -k;  
            flag = true;        
        }

        for(int i = 0; i < code.size(); ++i)
        {
            int sum = 0, j = i+1; 
            for(int l = 0; l < k; ++l)
            {
                sum += code[j%n];
                j++;
            }
            ans[i] = sum;
        }
        if(flag) 
        {
            reverse(ans.begin(),ans.end());
        }
        return ans;
    }
};