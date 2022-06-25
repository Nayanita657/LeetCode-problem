https://leetcode.com/problems/binary-tree-right-side-view/

************************************SOLUTION************************************************

 vector<int> rightSideView(TreeNode* root) 
    {
        if(root == NULL)
            return {};
        vector<int> result;
        queue<TreeNode*> pendingQueue;
        pendingQueue.push(root);
        pendingQueue.push(NULL);
        int temp;
        while(!pendingQueue.empty())
        {
            TreeNode* front = pendingQueue.front();
            pendingQueue.pop();
            if(front == NULL)
            {
                if(pendingQueue.size() == 0)
                {
                    result.push_back(temp);
                    break;
                }
                else
                {
                    result.push_back(temp);
                    pendingQueue.push(NULL);
                }
            }
            else
            {
                temp = front->val;
                if(front->left != NULL)
                    pendingQueue.push(front->left);
                if(front->right != NULL)
                    pendingQueue.push(front->right);
            }
        }
        return result;
    }
