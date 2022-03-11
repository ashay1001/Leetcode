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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(!head) return head;
        
        ListNode *temp = head;
        
        int count = 1;
        
        while(temp->next != NULL)
        {
            count++;
            temp = temp->next;
        }
        count = count - k % count;
        temp->next = head;      //making list circular
        
        while(count > 0)
        {
            temp = temp->next;
            count--;
        }
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};