class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode l3(0);
        ListNode* temp = &l3;
        
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                temp->next=l1;
                l1=l1->next;
            }
            else
            {
                temp->next=l2;
                l2=l2->next;
            }
            temp=temp->next;
        }
        
        temp->next = l1 ? l1 : l2;
        
        return l3.next;
    }
};