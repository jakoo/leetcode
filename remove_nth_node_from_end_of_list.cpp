/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* front = head;
        ListNode* behind = head;
        ListNode* behind2 = NULL;
        for (int i = 0; i < n; ++i)
            front = front->next;
            
        while (front != NULL)
        {
            front = front->next;
            behind2 = behind;
            behind = behind->next;
        }
            
        if (behind2 == NULL) // head will be deleted
            return behind->next;
        
        behind2->next = behind->next;
        return head;
    }
};