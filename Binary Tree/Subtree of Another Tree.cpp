https://leetcode.com/problems/subtree-of-another-tree/

****************************************SOLUTION************************************

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
    bool isIdentical(TreeNode* root, TreeNode* subRoot)
    {
        if(root == NULL && subRoot == NULL)
            return true;
        else if(root == NULL && subRoot != NULL)
            return false;
        else if(root != NULL && subRoot == NULL)
            return false;
        else
        {
            return (root->val == subRoot->val) && isIdentical(root->left, subRoot->left) && isIdentical(root->right, subRoot->right);
        }
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        if(root == NULL)
            return false;
        else
        {
            if(root->val == subRoot->val)
            {
                bool result = isIdentical(root, subRoot);
                if(result == true)
                    return true;
                else
                {
                    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
                    
                }
            }
            else
            {
                return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
            }
        }
        
    }
};
