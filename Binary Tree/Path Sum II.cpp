https://leetcode.com/problems/path-sum-ii/

***********************************SOLUTION***************************************

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
    vector<vector<int>> result;
    vector<int> inner_vec;
    void helper(TreeNode* root, int targetSum, int CurrentSum)
    {
        if(root == NULL)
            return;
        if(root->left == NULL && root->right == NULL)
        {
            CurrentSum = CurrentSum + root->val;
            if(CurrentSum == targetSum)
            {
                inner_vec.push_back(root->val);
                result.push_back(inner_vec);
                inner_vec.pop_back();
            }
        }
        else
        {
            CurrentSum = CurrentSum + root->val;
            inner_vec.push_back(root->val);
            helper(root->left, targetSum, CurrentSum);
            helper(root->right, targetSum, CurrentSum);
            inner_vec.pop_back();
        }
    }
    
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        if(root == NULL)
            return {};
        else
        {
            int currentsum = 0;
            helper(root, targetSum, currentsum);
        }
        return result;
    }
};
