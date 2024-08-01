
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
    ListNode * reversell(ListNode * head){
        ListNode * next=NULL;
        ListNode * pre =NULL;
        while(head!=NULL){
            next=head->next;
            head->next=pre;
            pre=head;
            head=next;
        }
        return pre;
    }
    bool isPalindrome(ListNode* head) {
         ListNode* fast=head;
        ListNode * slow=head;
        ListNode * entry = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
           
        }
        slow->next=reversell(slow->next);
        slow=slow->next;
        while(slow!=NULL){
            if(slow->val !=entry->val) return false;
            slow=slow->next;
            entry=entry->next;
        }
        return true;
        
    }
};