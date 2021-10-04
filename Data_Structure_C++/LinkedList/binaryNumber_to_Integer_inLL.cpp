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
    int getDecimalValue(ListNode* head) 
    {
        ListNode* p=head;
        int c=0;
        while(p){
            c++;
            p=p->next;
        }
        
        ListNode* q=head;
        int sum=0;
        while(q){
            if(q->val==1){
                sum=sum+ pow(2,(c-1));
            }
            else{
                sum=sum+0;
            }
            q=q->next;
            c--;
        }
        
        return sum;
        
    }
};