class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,bool>mp1;
        vector<vector<int>>ans(2);
        for(auto x:nums1)
        {
            mp1[x]=true;
        }

        // vector<int>v1;
        // vector<int>v2;

        for(auto x:nums2)
        {
            if(mp1[x]==false)
            {
                ans[1].push_back(x);
                // v1.push_back(x);
                mp1[x] = true;
            }
        }
        mp1.clear();

        for(auto x:nums2)
        {
            mp1[x]=true;
        }

        for(auto x:nums1)
        {
            if(mp1[x]==false)
            {
                ans[0].push_back(x);
                // v1.push_back(x);
                mp1[x] = true;
            }
        }

        return ans;
    }
};