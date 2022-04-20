// You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake.
// Recover the tree without changing its structure.

// Example 1:
// Input: root = [1,3,null,null,2]
// Output: [3,1,null,null,2]
// Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.

// Example 2:
// Input: root = [3,1,4,null,null,2]
// Output: [2,1,4,null,null,3]
// Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.

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
    vector<int> Ino;
    void recoverTree(TreeNode* root) {
        TreeNode *current = root;
        Inorder(root);
        sort(Ino.begin(),Ino.end());
        stack<TreeNode *> st;
        int i  = 0;
        while (current != NULL || st.empty() == false)
        {
            while (current !=  NULL)
            {
                st.push(current);
                current = current->left;
            }

            current = st.top();
            st.pop();
            if(Ino[i] != current->val)
            {
                current->val = Ino[i];
            }
            i++;
            current = current->right;

        } 
    }
    
    void Inorder(TreeNode* root)
    {
       if(root == NULL)
       {
           return;
       }
        Inorder(root->left);
        Ino.push_back(root->val);
        Inorder(root->right);
    }
};