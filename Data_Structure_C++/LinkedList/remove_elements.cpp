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