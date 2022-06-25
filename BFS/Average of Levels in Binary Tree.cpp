https://leetcode.com/problems/average-of-levels-in-binary-tree/

********************************************SOLUTION*****************************************

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
    vector<double> averageOfLevels(TreeNode* root) 
    {
        vector<double> result;
        queue<TreeNode*> pendingQueue;
        pendingQueue.push(root);
        pendingQueue.push(NULL);
        double sum = 0;
        int node_at_level = 0;
        while(!pendingQueue.empty())
        {
            
            TreeNode* front = pendingQueue.front();
            pendingQueue.pop();
            if(front == NULL)
            {
                if(pendingQueue.size() == 0)
                {
                    result.push_back(sum / node_at_level);
                    break;
                }
                    
                else
                {
                    result.push_back(sum / node_at_level);
                    sum = 0;
                    node_at_level = 0;
                    pendingQueue.push(NULL);
                }
            }
            else
            {
                sum = sum + front->val;
                node_at_level++;
                if(front->left != NULL)
                    pendingQueue.push(front->left);
                if(front->right != NULL)
                    pendingQueue.push(front->right);
            }
        }
        return result;
    }
};
