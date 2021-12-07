
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        
        int number = head->val;
        while(head->next != NULL)
        {
            number = (number<<1) + head->next->val;
            head = head->next;
        }
        return number;
    }
};

/*
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        
        int number = head->val;
        while(head->next != NULL)
        {
            number = (number<<1) | head->next->val;
            head = head->next;
        }
        return number;
    }
};

*/
