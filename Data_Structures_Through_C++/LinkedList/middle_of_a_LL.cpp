//Problem Number 876 labelled as easy

//Given the head of a singly linked list, return the middle node of the linked list.

//If there are two middle nodes, return the second middle node.

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