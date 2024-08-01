class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy=new ListNode(-1,head);
        head=dummy;
        ListNode* ptr=head;
        while(ptr->next!=NULL){
            if(ptr->next->val==val){
                ptr->next=ptr->next->next;
                continue;
            }
            ptr=ptr->next;
        }
        return head->next;

    }
};