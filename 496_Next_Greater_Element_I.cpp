class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int>ans;
        stack<int>st;
        unordered_map<int,int>mp;
        int n = nums2.size();
        st.push(nums2[n-1]);
        mp[nums2[n-1]] = -1;
        for(int i = n-2; i >=0; i--)
        {
            if(st.empty()==true)
            {
                mp[nums2[i]] = -1;
            }
            else
            {
                while(!st.empty() && st.top() < nums2[i])
                {
                    st.pop();
                }
                if(st.empty()==true)
                {
                    mp[nums2[i]] = -1;
                }
                else
                {
                    mp[nums2[i]] = st.top();
                }
                st.push(nums2[i]);
            }
        }   
        
        for(int i = 0; i < nums1.size(); i++)
        {
            ans.push_back(mp[nums1[i]]);
        }
        
        return ans;
    }
};