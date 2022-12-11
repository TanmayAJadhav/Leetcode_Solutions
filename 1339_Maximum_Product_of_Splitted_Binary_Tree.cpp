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
    long long int totalsum = 0;
    long long int ans = 0;
    void findtotsum(TreeNode* root)
    {
        if(!root)
        {
            return;
        }
        findtotsum(root->left);
        findtotsum(root->right);
        totalsum += root->val;  
    }

    long long int helper(TreeNode* root)
    {
        if(!root)
        {
            return 0;
        }
        long long int sumofsubtree = 0;
        sumofsubtree += helper(root->left);
        sumofsubtree += helper(root->right);
        sumofsubtree += root->val;
        ans = max(ans,((totalsum-sumofsubtree)*sumofsubtree));
        return sumofsubtree;
    }


    int maxProduct(TreeNode* root) {
        findtotsum(root);
        long long int tot = helper(root);

        return ans%1000000007;
    }
};