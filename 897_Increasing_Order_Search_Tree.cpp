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
    TreeNode *current;
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *dummy = new TreeNode(0);
        current = dummy;
        Inorder(root);
        return dummy->right;
    }
    
    void Inorder(TreeNode* root)
    {
        if(root == NULL)
        {
            return;
        }
        Inorder(root->left);
        root->left = NULL;
        current->right = root;
        current = current->right;
        Inorder(root->right);
    }
    
};