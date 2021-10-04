// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */

class Solution {
public:
bool isPalindrome(ListNode* head) {

 vector<int>v;
 ListNode* temp=head;
 while(temp!=NULL){
     v.push_back(temp->val);
     temp=temp->next;
}

 vector<int> v2=v;
 reverse(v.begin(),v.end());

 if(v==v2) return true;
 else return false;
}
};