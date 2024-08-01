/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* realFlatten(Node*prev, Node*down,Node* next){
        Node*ptr=down;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        
        prev->next=down;
        down->prev=prev;
        ptr->next=next;
        if(next!=NULL) next->prev=ptr;
        prev->child=NULL;
        return prev;
    }
    Node* flatten(Node* head) {
        Node*ptr=head;
        while(ptr!=nullptr){
            if(ptr->child!=NULL){
                ptr=realFlatten(ptr,ptr->child,ptr->next);
            }
            ptr=ptr->next;
        }
        return head;
    }
};