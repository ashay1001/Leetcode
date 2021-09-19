/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int lenA = 0,lenB = 0;
        ListNode* t1 = headA;
        ListNode* t2 = headB;
        
        while(t1)
        {
            lenA++;
            t1 = t1->next;
        }
        
        while(t2)
        {
            lenB++;
            t2 = t2->next;
        }
        
        t1 = headA;
        t2 = headB;
        
        if(lenA > lenB)
        {
            for(int i=0; i < lenA-lenB; i++)
            {
                t1 = t1->next;
            }
        }
        else
        {
            for(int i=0; i < lenB-lenA; i++)
            {
                t2 = t2->next;
            }
        }
        
        while(t1 != t2)
        {
            t1 = t1->next;
            t2 = t2->next;
        }
        
        return t1;
    }
};