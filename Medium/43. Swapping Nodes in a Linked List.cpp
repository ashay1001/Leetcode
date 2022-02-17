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
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode *ptr1 = head, *ptr2 = head, *kth = NULL;
        
        while(k > 1)
        {
            ptr1 = ptr1->next;
            k--;
        }
        kth = ptr1;
        
        while(ptr1->next != NULL)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        swap(kth->val, ptr2->val);
        return head;
    }
};