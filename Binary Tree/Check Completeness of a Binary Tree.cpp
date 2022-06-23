https://leetcode.com/problems/check-completeness-of-a-binary-tree/

************************************************SOLUTION**************************************************

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
    stack<int> s;
    bool isCompleteTree(TreeNode* root) 
    {
        bool end = false;
        queue<TreeNode*> pendingQueue;
        pendingQueue.push(root);
        while(!pendingQueue.empty())
        {
            TreeNode* front_node = pendingQueue.front();
            pendingQueue.pop();
            if(front_node == NULL)
                end = true;
            else
            {
                if(end)
                    return false;
                else
                {
                    pendingQueue.push(front_node->left);
                    pendingQueue.push(front_node->right);
                }
            }
        }
        return true;
    }
};
