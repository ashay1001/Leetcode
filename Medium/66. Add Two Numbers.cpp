class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    
        ListNode dummy(0), *curr = &dummy;
        int carry = 0;
    
        while (l1 || l2 || carry) 
        {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return dummy.next;
    }
};