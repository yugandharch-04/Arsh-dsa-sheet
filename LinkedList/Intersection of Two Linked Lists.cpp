/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {


        //O(N^2) approach 


        // ListNode * dummyA=headA,*dummyB=headB;
        // while(dummyA!=NULL){
        //     dummyB=headB;
        //     while(dummyB!=NULL){
        //         if(dummyB==dummyA) return dummyB;
        //         dummyB=dummyB->next;
        //     }
        //     dummyA=dummyA->next;
        // }
        // return NULL;

        //O(N) approach

        unordered_set<ListNode*>mpp;
        for (auto p = headA ; p!=NULL ; p = p->next){
            mpp.insert(p);
        }
        for (auto p = headB ; p!=NULL ; p = p->next){
            if (mpp.find(p)!=mpp.end()) return p;
        }
        return NULL; 
    }
};