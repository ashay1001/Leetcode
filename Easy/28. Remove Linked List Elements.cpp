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
    ListNode* removeElements(ListNode* head, int data) {
     
        if(head == NULL) {return NULL;}
        
        while(head->val == data)
        {
            if(head->next ==  NULL) {return NULL;}
            ListNode *temp = head;
            head=head->next;
            delete(temp);
        }
        
        ListNode *prev = head, *curr = head;
        while(curr != NULL)
        {
            if(curr->val == data)
            {
                ListNode *temp = curr;
                curr = curr->next;
                prev->next = curr;
                delete(temp);
            }
            else
            {
                prev = curr;
                curr = curr->next;   
            }
        }
        return head;
    }
};