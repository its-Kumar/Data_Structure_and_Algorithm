//Problem Number 160 labelled as easy

//Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p;
        p=headA;
        stack <ListNode*> s1;
        stack <ListNode*> s2;
        while(p!=NULL)
        {
            s1.push(p);
            p=p->next;
        }
        p=headB;
        while(p!=NULL)
        {
            s2.push(p);
            p=p->next;
        }
        while(s1.top()==s2.top())
        {
            p=s1.top();
            s1.pop();
            s2.pop();
            if(s1.empty() || s2.empty())
                break;
        }
        return p;
    }
};