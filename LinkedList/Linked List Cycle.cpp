https://leetcode.com/problems/linked-list-cycle/

********************************SOLUTION*****************************


bool hasCycle(ListNode *head) 
    {
        if(head == NULL || head->next == NULL)
            return false;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        slow = slow->next;
        fast = fast->next->next;
        
        while(fast != NULL && fast->next != NULL)
        {
            if(slow == fast)
            {
                //if(fast->next == )
                return true;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
        
    }
