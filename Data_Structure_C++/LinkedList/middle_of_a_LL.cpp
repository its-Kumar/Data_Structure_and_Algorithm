class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        //Two Pointer Approach
        if(head->next==NULL || head==NULL){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};