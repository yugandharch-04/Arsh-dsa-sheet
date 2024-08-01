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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head=NULL,*tail,*p1,*p2;
        p1=l1;
        p2=l2;
        int s;
        int c=0;
        while(true){
            if((p1==NULL)||(p2==NULL)) break;
            if(((p1->val)+(p2->val)+c)>9){
                s=((p1->val)+(p2->val)+c)%10;
                c=1;
            }
            else{
                s=(p1->val)+(p2->val)+c;
                c=0;
            }
            if(head==NULL){
                head=new ListNode(s);
                tail=head;
            }
            else{
                
                tail->next=new ListNode(s);
                tail=tail->next;
               
            }
            p1=p1->next;
            p2=p2->next;
        }

        
        while(p1!=NULL){
            s=p1->val+c;
            if(s>9){
                tail->next=new ListNode(s%10);
                tail=tail->next;
            }
            else{
                tail->next=new ListNode(s);
                tail=tail->next;
                c=0;
            }
            p1=p1->next;
        }
        while(p2!=NULL){
            s=p2->val+c;
            if(s>9){
                tail->next=new ListNode(s%10);
                tail=tail->next;
            }
            else{
                tail->next=new ListNode(s);
                tail=tail->next;
                c=0;
            }
            p2=p2->next;
        }

        if(c){
            tail->next=new ListNode(1);
            tail=tail->next;
        }
        
        return head;
    }
};