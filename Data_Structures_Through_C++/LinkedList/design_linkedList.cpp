//Problem Number 707 labelled as Medium

// Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
// A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
// If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

// Implement the MyLinkedList class:

// MyLinkedList() Initializes the MyLinkedList object.
// int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
// void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
// void addAtTail(int val) Append a node of value val as the last element of the linked list.
// void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
// void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.
 



class MyLinkedList {

public: 
    struct ListNode{
        int val;
        ListNode *pre;
        ListNode *next;
        ListNode(int x):val(x),pre(NULL),next(NULL){}
    };
    
        ListNode *head=NULL;
        ListNode *end=NULL;
        int len;
    
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = new ListNode(-1);
        end  = new ListNode(-1);
        
        head->next=end;
        end->pre=head;
        
        len=0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index >=len||index <0) return -1;
        
        int seq=0;
        ListNode *current = head->next;
        while(current){
            if(seq==index)return current->val;
            else {
                current=current->next;
                seq++;
            }
        }
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode *temp = new ListNode(val);
        temp->next=head->next;
        head->next->pre=temp;
        head->next=temp;
        temp->pre=head;
        
        len++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode *temp = new ListNode(val);
        temp->pre=end->pre;
        end->pre->next=temp;
        end->pre=temp;
        temp->next=end;
    
        len++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index>len||index<0)return;
        if(index==0){
            addAtHead(val);
            return;
        }
        
        int seq=0;
        ListNode *current = head->next;
        
        while(current){
            if(seq==index-1){
                ListNode *temp = new ListNode(val);
                temp->next=current->next;
                current->next->pre=temp;
                temp->pre=current;
                current->next=temp;
                break;
            }
            else{
                current=current->next;
                seq++;
            }
        }
        
        len++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index >=len||index <0) return;
        
        int seq=0;
        ListNode *current = head->next;
        
        while(current){
            if(seq==index){
                current->next->pre=current->pre;
                current->pre->next=current->next;
                delete current;
                break;
            }
            else{
                current=current->next;
                seq++;
            }
        }
        
        len--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */