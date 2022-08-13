//                              1,2,3
                                 
//                 1               2               3
                        
//              1,2  1,3       2,3  2,1        3,1   3,2
                        
//             1,2,3 1,3,2     2,3,1 2,1,3     3,1,2 3,2,1                      

class Solution {
private:
    vector<bool>visited;
    vector<int>ds;
    vector<vector<int>>ans;
public:
    
    void helper(vector<int>& nums, int index)
    {
        if(ds.size() == nums.size())
        {
            ans.push_back(ds);
            return;
        }
        
        for(int i = 0; i < nums.size(); ++i)
        {
            if(visited[i] == false)
            {
                ds.push_back(nums[i]);
                visited[i] = true;
                helper(nums,i+1);
                visited[i] = false;
                ds.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums)
    {
        visited.resize(nums.size());
        helper(nums, 0);
        return ans;
    }
    
};