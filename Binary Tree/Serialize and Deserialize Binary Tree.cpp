https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

**************************************SOLUTION********************************************


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string helper(TreeNode* root)
    {
        string input;
        queue<TreeNode*> pendingQueue;
        pendingQueue.push(root);
        input+=to_string(root->val);
        input+=',';
        while(!pendingQueue.empty())
        {
            TreeNode* front = pendingQueue.front();
            pendingQueue.pop();
            
            
            if(front->left != NULL)
            {
                pendingQueue.push(front->left);
                input+=to_string(front->left->val);
                input+=',';
            }
            else
            {
                input+='#';
                input+=',';
            }
            if(front->right != NULL)
            {
                pendingQueue.push(front->right);
                input+=to_string(front->right->val);
                input+=',';
            }
            else
            {
                input+='#';
                input+=',';
            }
            
        }
        return input;
    }
    string serialize(TreeNode* root) 
    {
        
        if(root == NULL)
            return "";
        else
        {
            string result = helper(root);
            //cout<<result;
            return result;
        }
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        
        if(data.length() == 0)
          return NULL;
        else
        {
            stringstream s(data);
            string str;
            getline(s, str, ',');
            TreeNode* root = new TreeNode(stoi(str));
            queue<TreeNode*> pendingQueue;
            pendingQueue.push(root);
            while(!pendingQueue.empty())
            {
                TreeNode* front = pendingQueue.front();
                pendingQueue.pop();
                //extracting the left child
                getline(s, str, ',');
                if(str != "#")
                {
                    TreeNode* leftchild = new TreeNode(stoi(str));
                    front->left = leftchild;
                    pendingQueue.push(leftchild);
                }
                else
                {
                    front->left = NULL;
                }
                //extracting the right child
                getline(s, str, ',');
                if(str != "#")
                {
                    TreeNode* rightchild = new TreeNode(stoi(str));
                    front->right = rightchild;
                    pendingQueue.push(rightchild);
                }
                else
                {
                    front->right = NULL;
                }
            }
            return root;
        }
        
        //return NULL;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
