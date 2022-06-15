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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(!head or !head->next or k==1) return head;
        
        ListNode *dummy = new ListNode(0), *begin;
        int i=1;
        
        dummy->next = head;
        *begin = *dummy;
        
        while(head)
        {
            if(i%k == 0)
            {
                begin = reverse(begin, head->next);
                head = begin->next;
                i++;
            }
            else
            {
                head = head->next;
                i++;
            }
        }
        return dummy->next;
    }
    
    ListNode* reverse(ListNode *begin, ListNode *end)   //This function reverses the linked list present between begin and end
    {
        //begin->next represents 1st element of linked list to be reversed. 
        //Hence it is going to be the last element after reversal
        //after reversal prev will contain the new head i.e the start of reverse linked list
        
        ListNode *prev = NULL, *curr = begin->next, *next = NULL, *temp = begin->next;
        
        while(curr != end)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        begin->next = prev;
        temp->next = end;
        
        return temp;    //this will be the new begin for next k set of nodes that needs to be reversed
    }
};