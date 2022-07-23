https://leetcode.com/problems/linked-list-cycle-ii/

***************************SOLUTION****************************

ListNode *detectCycle(ListNode *head) 
    {
        if(head == NULL || head->next == NULL)
            return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        slow = slow->next;
        fast = fast->next->next;
        
        bool flag = false;
        while(fast != NULL && fast->next != NULL)
        {
            if(slow == fast)
            {
                flag = true;
                break;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        if(flag == false)
            return NULL;
        else
        {
            //take another pointer and iterrate until slow and that pointer becomes same
            ListNode* entry = head;
            while(entry != slow)
            {
                entry = entry->next;
                slow = slow->next;
            }
            return slow;
        }
    }
