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
       ListNode* curr1=headA;
       ListNode* curr2=headB;
       int f1=0,f2=0;
       while((curr1!=NULL || curr2!=NULL) && curr1!=curr2 ){
         curr1=curr1->next;
         curr2=curr2->next;
         if(curr1==NULL && f1==0)
        {
           curr1=headB;
           f1=1;
        }
       
        if(curr2==NULL && f2==0){
            curr2=headA;
            f2=1;
        }
       
       }
       return curr1; 
    }
};