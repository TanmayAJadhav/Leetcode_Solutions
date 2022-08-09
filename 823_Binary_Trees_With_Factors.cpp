class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        unordered_map<int,long long int>m;
        
        for(int ele : arr)
        {
            m[ele] = 1;
        }
        
        long long int cnt = 0;
        for(int i = 1; i < arr.size(); ++i)
        {
            cnt = 0;
            for(int j = 0; j < i; ++j)
            {
                if(arr[i]%arr[j] == 0 && m[arr[i]/arr[j]])
                {
                    cnt += m[arr[j]]*m[arr[i]/arr[j]];
                }
            }
            m[arr[i]] += cnt;
        }
        
        long long int ans = 0;
        for(auto it : m)
        {
            ans += it.second;
        }
        
        return ans%1000000007;
    }
};