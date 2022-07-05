https://leetcode.com/problems/count-good-nodes-in-binary-tree/

********************************SOLUTION************************************

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
    int count = 0;
    void helper(TreeNode* root, int cur_max)
    {
        if(root == NULL)
            return;
        else
        {
            if(root->val == cur_max || root->val > cur_max)
            {
                count++;
                cur_max = root->val;
            }
            helper(root->left, cur_max);
            helper(root->right, cur_max);
        }
    }
    
    int goodNodes(TreeNode* root) 
    {
        int cur_max = root->val;
        helper(root, cur_max);
        return count;
    }
};
