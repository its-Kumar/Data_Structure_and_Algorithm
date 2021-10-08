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

//Problem Number 203 labelled as easy

//Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        if(!head) return head;
        
        while(head && head->val==val){
            head=head->next;
        } //if the value of head is equal to the value which has to be deleted then move the head pointer
        
        ListNode* p=head;
        
        while(p){
            if(p->next && p->next->val==val){
                p->next=p->next->next;
            }
            else{
                p= p->next;
            }
        
        }
            return head;
        
    }
        

    
};