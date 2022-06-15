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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(!head) return head;
        
        ListNode *dummy = new ListNode(0), *slow, *fast;
        dummy->next = head;
        slow = dummy, fast = dummy;        
        
        for(int i=0; i<n; i++)
            fast = fast->next;
        
        while(fast->next)
        {
            fast = fast->next; slow = slow->next;
        }
        
        ListNode *node = slow->next;
        slow->next = slow->next->next;
        delete node;
        return dummy->next;
    }
};  