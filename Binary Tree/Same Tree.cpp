https://leetcode.com/problems/same-tree/

*******************************************SOLUTION**********************************

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
    
    void postorder(vector<int>& temp, TreeNode* root)
    {
        if(root == NULL)
            temp.push_back(INT_MIN);
        else
        {
            postorder(temp, root->left);
            if(root->left != NULL)
                temp.push_back(root->left->val);
            
            postorder(temp, root->right);
            if(root->right != NULL)
                temp.push_back(root->right->val);
            
            temp.push_back(root->val);
        }
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        vector<int> post1;
        vector<int> post2;
        postorder(post1, p);
        postorder(post2, q);
        
        if(post1.size() == post2.size())
        {
            for(int i = 0; i < post1.size(); i++)
            {
                if(post1[i] == post2[i])
                    continue;
                else
                    return false;
            }
            return true;
        }
        else
            return false;
        
    }
};
