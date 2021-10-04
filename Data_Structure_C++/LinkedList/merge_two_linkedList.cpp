class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(!l1) return l2;
        if(!l2) return l1;
        
        ListNode* head=l1;
        
        if(l1->val > l2->val){
            head=l2;
            l2=l2->next;
        }
        else
        {
            l1=l1->next;
        }
        
        ListNode* curr=head;
        while(l1 && l2){
            if(l1->val < l2->val){
                curr->next=l1;
                l1=l1->next;
            }else {
                curr->next=l2;
                l2=l2->next;
            }
            curr=curr->next;
        }
        if(!l1) curr->next=l2;
        else curr->next=l1;;
        
        return head;
        
    }
};