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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)
        {
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        bool lefttoright = true;

        while(!q.empty())
        {
            int nsize = q.size();
            vector<int>row(nsize);

            for(int i = 0; i < nsize; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                
                // int index = lefttoright ? i : (nsize - i - 1);

                row[i] = (node->val);

                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }
            }
            if(lefttoright==false)
            {
                reverse(row.begin(),row.end());
            }
            ans.push_back(row);
            lefttoright = !lefttoright;
        }  

        return ans;
    }
};