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
    ListNode *detectCycle(ListNode *head) {
       ListNode* slow=head;
        ListNode* fast=head;
        ListNode* temp=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
            if(slow==temp)
            return temp;
            while(slow!=temp){
                slow=slow->next;
                temp=temp->next;
                if(slow==temp)
                return temp;
               }
            }
        }
        return NULL;  
    }
};