class Solution {
public:
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode*current=head;
        ListNode*prev=NULL;
        ListNode*next=NULL;
        while(current!=NULL){
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*b=reverseLinkedList(slow->next);
        slow->next=NULL;
        // 2nd part
        ListNode*a=head;
        ListNode*tempA=a;
        ListNode*tempB=b;
        ListNode*c=new ListNode(-1);
        ListNode*tempC=c;
        while(tempA!=NULL && tempB!=NULL) {
            tempC->next=tempA;
            tempA=tempA->next;
            tempC=tempC->next;

            tempC->next=tempB;
            tempB=tempB->next;
            tempC=tempC->next;
        }
        tempC->next=tempA;
        head=c->next;
    }
};