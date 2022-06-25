https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

*****************************************SOLUTION**************************************************************
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        unordered_map<int, TreeNode*> map;
        //updating the parent node
        queue<TreeNode*> pendingQueue;
        pendingQueue.push(root);
        map[root->val] = NULL;
        TreeNode* targetNode;
        while(!pendingQueue.empty())
        {
            TreeNode* front = pendingQueue.front();
            if(front == target)
                targetNode = front;
            pendingQueue.pop();
            if(front->left != NULL)
            {
                pendingQueue.push(front->left);
                map[front->left->val] = front;
            }
            if(front->right != NULL)
            {
                pendingQueue.push(front->right);
                map[front->right->val] = front;
            }
        }
        queue<TreeNode*> temp_queue;
        //cout<<targetNode->val<<"\n";
        
        temp_queue.push(targetNode);
        temp_queue.push(NULL);
        int *visited = new int[500];
        for(int i = 0; i < 500; i++)
        {
            visited[i] = 0;
        }
        while(k > 0)
        {
            //searching parent
            TreeNode* curr_Node = temp_queue.front();
            
            temp_queue.pop();
            if(curr_Node == NULL)
            {
                k--;
                temp_queue.push(NULL);
            }
            else
            {
                visited[curr_Node->val] = 1;
                auto itr = map.find(curr_Node->val);
                TreeNode* parent = itr->second;
                if(parent != NULL && visited[parent->val] != 1)
                {
                    temp_queue.push(parent);
                    visited[parent->val] = 1;
                }
                
                if(curr_Node->left != NULL && visited[curr_Node->left->val] != 1)
                {
                    temp_queue.push(curr_Node->left);
                    visited[curr_Node->left->val] = 1;
                }
                
                if(curr_Node->right != NULL && visited[curr_Node->right->val] != 1)
                {
                    temp_queue.push(curr_Node->right);
                    visited[curr_Node->right->val] = 1;
                }
                 
            }
            
            
        }
        vector<int> result;
        while(temp_queue.front() != NULL)
        {   
            TreeNode* curr_Node = temp_queue.front();
            result.push_back(curr_Node->val);
            temp_queue.pop();
        }
        return result;
    }
};  
  
