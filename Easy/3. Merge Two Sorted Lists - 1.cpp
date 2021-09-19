class Solution {
public:
    void insertAtEnd(ListNode* &head, int val)
    { 
        ListNode* n=new ListNode(val);
    
        if(head == NULL)
        {
            head=n;
        }
        else
        {
            ListNode* temp=head;
            while(temp->next != NULL)
            {
                temp=temp->next;
            }
            temp->next = n;
        }

    }
    
    
    void insertRem(ListNode* &head, ListNode* &l)
    {
        ListNode* temp = head;
        while(temp->next != NULL)
        {
            temp=temp->next;
        }
        while(l)
        {   
            ListNode* n=new ListNode(l->val);
            temp->next=n;
            temp=n;
            l=l->next;
        }
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(l1==NULL && l2==NULL) {return NULL;}
        if(l1==NULL && l2!=NULL) {return l2;}
        if(l1!=NULL && l2==NULL) {return l1;}
        
        ListNode* l3=NULL;

        while(l1 !=NULL && l2 !=NULL)
        {
            if(l1->val < l2->val)
            {
                insertAtEnd(l3,l1->val);
                l1=l1->next;
            }
            else
            {
                insertAtEnd(l3,l2->val);
                l2=l2->next;
            }
        }
        
        if(l1 == NULL) { insertRem(l3,l2); }
        else { insertRem(l3,l1); }
        
        return l3;    
    }
};