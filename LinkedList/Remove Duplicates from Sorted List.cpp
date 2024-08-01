 ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return head;
        ListNode * dummy = head;
        while(dummy->next!=NULL){
            if(dummy->next->val==dummy->val ){
                dummy->next=dummy->next->next;
            }
            else
            {
                dummy=dummy->next;
            }
        }
        return head;
    }