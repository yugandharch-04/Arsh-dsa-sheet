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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * ptr=head;
        ListNode * ptr2=head;
        int t=n;
        while(t--){
            ptr2=ptr2->next;
        }
        if(ptr2==NULL){
            head=head->next;
            return head;
        }
        
        while(ptr2->next!=NULL){
            ptr2=ptr2->next;
            ptr=ptr->next;
        }
        if(n==1){
            ptr->next=NULL;
        }
        else ptr->next=ptr->next->next;
        return head;
    }
};