https://leetcode.com/problems/remove-nth-node-from-end-of-list/

***********************************SOLUTION****************************************************


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        //placing the fast pointer the nth distance
        for(int i = 1; i <= n; i++)
        {
            fast = fast->next;
        }
        //untill fast reaches to the last node move the slow and fast by 1 distance
        while(fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
        //once we place the slow at the correct position now connect slow pointer to next of fast pointer
       
        slow->next = slow->next->next;
        return dummy->next;
    }
};
