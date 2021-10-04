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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL) return NULL;
        
        ListNode* odd= head;
        ListNode* even= head->next;
        ListNode* evenStart= even;
        
        while(even && even->next){
            
            odd->next= even->next;
            odd=odd->next;
            even->next=odd->next;
            even=even->next;
            
        }
        odd->next=evenStart;
        return head;
    }
};