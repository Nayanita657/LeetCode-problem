/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        if(head!=NULL)
        {
            ListNode *prev = NULL;
            ListNode *next = NULL;
            ListNode *curr = head;
    
            ListNode *temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
    
            while(curr != NULL)
            {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            return temp;
            
        }
        else
        {
            return head;
        }
    }
};
