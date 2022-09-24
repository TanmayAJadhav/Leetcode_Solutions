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
class Solution  {
vector<vector<int>>ans;
vector<int>nums;
public:
    void helper(TreeNode* root, int targetSum)
    {
        if(!root)
        {
            return;
        }
        
        targetSum -= root->val;
        nums.push_back(root->val);
        if((targetSum == 0) && (root->left == NULL) && (root->right == NULL))
        {
            ans.push_back(nums);
        }
        
        if (root->left)
        {
            helper(root->left,targetSum);
        }
        
        if (root->right) 
        {
            helper(root->right,targetSum);
        }
        
        nums.pop_back();
        targetSum += root->val;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        helper(root,targetSum);
        return ans;
    }
};