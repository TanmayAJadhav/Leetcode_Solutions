class Solution
{
public:
    int sum = 0;

    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root)
        {
            return false;
        }

        sum += root->val;
        if ((root->left == NULL) && (root->right == NULL) && (sum == targetSum))
        {
            return true;
        }

        bool l = hasPathSum(root->left, targetSum);
        bool r = hasPathSum(root->right, targetSum);
        sum -= root->val;

        return l || r;
    }
};