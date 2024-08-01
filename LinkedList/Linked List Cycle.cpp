class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode * ptr=head;
        ListNode * ptr2=head;
        while(ptr!=NULL && ptr->next!=NULL){
            ptr=ptr->next->next;
            ptr2=ptr2->next;
            if(ptr==ptr2) return true;
        }
       
        return false;
    }
};