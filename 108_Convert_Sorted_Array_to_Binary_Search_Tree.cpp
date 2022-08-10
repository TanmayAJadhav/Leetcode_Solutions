/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    TreeNode* helper(int start, int end, vector<int>& nums)
    {
        if(start > end)
        {
            return NULL;
        }
        
        int mid = (start+end)/2;
        TreeNode* newn = new TreeNode(nums[mid]);
        
        newn->left = helper(start,mid-1,nums);
        newn->right = helper(mid+1,end,nums);
        
        return newn;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(0,nums.size()-1,nums);
    }
};