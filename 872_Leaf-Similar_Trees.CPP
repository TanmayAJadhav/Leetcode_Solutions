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

    void preorder(TreeNode* root, vector<int>&v1)
    {
        if(root==NULL)
        {
            return;
        }

        if(root->left==NULL && root->right==NULL)
        {
            v1.push_back(root->val);
        }
        preorder(root->left,v1);
        preorder(root->right,v1);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>v1;
        vector<int>v2;
        preorder(root1,v1);
        preorder(root2,v2);
        
        if(v1.size() != v2.size())
        {
            return false;
        }
        for(int i = 0; i < v1.size(); ++i)
        {
            if(v1[i] != v2[i])
            {
                return false;
            }
        }
        return true;
        
    }
};