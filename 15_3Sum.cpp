//TLE
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>>s;
        unordered_map<int,int>mp;
        for(auto ele:nums)
        {
            mp[ele]++;
        }

        int a,b,c;
        for(int i = 0; i < n; ++i)
        {
            a = nums[i];
            mp[nums[i]]--;
            for(int j = i+1; j < n; ++j)
            {
                b = nums[j];
                mp[nums[j]]--;
                c = -(a+b);
                vector<int>temp;
                temp.push_back(a);
                temp.push_back(b);
                temp.push_back(c);
                sort(temp.begin(),temp.end());
                if(mp[c] > 0)
                {
                    s.insert(temp);
                    temp.clear();
                }
                mp[nums[j]]++;
            }
            mp[nums[i]]++;
        }
        vector<vector<int>>ans;
        for(auto v:s)
        {
            ans.push_back(v);
        }
        return ans;
    }
};class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>>s;
        unordered_map<int,int>mp;
        for(auto ele:nums)
        {
            mp[ele]++;
        }

        int a,b,c;
        for(int i = 0; i < n; ++i)
        {
            a = nums[i];
            mp[nums[i]]--;
            for(int j = i+1; j < n; ++j)
            {
                b = nums[j];
                mp[nums[j]]--;
                c = -(a+b);
                vector<int>temp;
                temp.push_back(a);
                temp.push_back(b);
                temp.push_back(c);
                sort(temp.begin(),temp.end());
                if(mp[c] > 0)
                {
                    s.insert(temp);
                    temp.clear();
                }
                mp[nums[j]]++;
            }
            mp[nums[i]]++;
        }
        vector<vector<int>>ans;
        for(auto v:s)
        {
            ans.push_back(v);
        }
        return ans;
    }
};