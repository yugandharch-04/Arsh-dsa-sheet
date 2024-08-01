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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy=new ListNode(-1);
        ListNode*ptr=dummy;
        while(head){
            if(head->next && head->next->val==head->val){
                while(head->next && head->next->val==head->val){
                    head=head->next;
                }
                head=head->next;
            }
            else{
                ptr->next=head;
                ptr=ptr->next;
                head=head->next;
                ptr->next=NULL;
            }
        }
        return dummy->next;
    }
};