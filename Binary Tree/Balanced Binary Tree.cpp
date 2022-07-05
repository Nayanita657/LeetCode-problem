https://leetcode.com/problems/balanced-binary-tree/

***************************************SOLUTION************************************

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
    
    pair<bool, int> helper(TreeNode* root)
    {
        if(root == NULL)
        {
            pair<bool, int> temp;
            temp.first = true;
            temp.second = 0;
            return temp;
        }
        else
        {
            pair<bool, int> lh = helper(root->left);
            pair<bool, int> rh = helper(root->right);
            pair<bool, int> temp;
            if(lh.first == true && rh.first == true)
            {
                int balance_factor = lh.second - rh.second;
                if(balance_factor == 0 || balance_factor == 1 || balance_factor == -1)
                    temp.first = true;
                else
                    temp.first = false;
                temp.second = 1 + max(lh.second, rh.second);
            }
            else
            {
                temp.first = false;
                temp.second = 0;
            }
            return temp;
        }
    }
    
    bool isBalanced(TreeNode* root) 
    {
        if(root == NULL)
            return true;
        else
        {
            pair<bool, int> result;
            result = helper(root);
            return result.first;
        }
    }
};
