
/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int findMergeNode(SinglyLinkedListNode *head1, SinglyLinkedListNode *head2)
{
    SinglyLinkedListNode *p1 = head1, *p2 = head2;
    while (p1 != NULL)
    {
        p2 = head2;
        while (p2 != NULL && (p1 != p2))
            p2 = p2->next;
        if (p1 == p2)
            break;
        p1 = p1->next;
    }
    return p1->data;
}
