https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

**********************************************SOLUTION**************************************************
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) 
    {
        if(root == NULL)
            return NULL;
        queue<Node*> pendingQueue;
        pendingQueue.push(root);
        pendingQueue.push(NULL);
        while(!pendingQueue.empty())
        {
            Node* front1 = pendingQueue.front();
            pendingQueue.pop();
            if(front1 == NULL)
            {
                if(pendingQueue.size() == 0)
                    break;
                else
                {
                    pendingQueue.push(NULL);
                }
            }
            else
            {
                Node* front2 = pendingQueue.front();
                front1->next = front2;
                if(front1->left != NULL)
                    pendingQueue.push(front1->left);
                if(front1->right != NULL)
                    pendingQueue.push(front1->right);
                
            }
        }
        
        return root;
    }
};
