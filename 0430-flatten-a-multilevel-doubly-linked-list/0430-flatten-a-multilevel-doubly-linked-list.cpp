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
    Node* rec(Node* head){
        Node* temp=head;
        Node* res=new Node(0);
        Node* ans=res;
        while(temp!=NULL){
           Node* a=new Node(temp->val);
           ans->next=a;
           a->prev=ans;
           ans=ans->next;
           if(temp->child!=NULL){
             Node *k=rec(temp->child);
             ans->next=k;
             k->prev=ans;
             Node* tp1=res;
             while(tp1->next!=NULL){
                tp1=tp1->next;
             }
             ans=tp1;
           } 
           temp->child=NULL;
           temp=temp->next;
        }
        Node* k=res->next;
        k->prev=NULL;
        return k;
    }
    Node* flatten(Node* head) {
      if(head==NULL)
      return NULL;
      Node* res=rec(head);
      Node* temp=res;
      return  res; 
    }
};