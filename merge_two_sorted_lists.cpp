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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
            
        ListNode* p, *head;
        if (l1->val > l2->val)
        {
            head = l2;
            p = l2;
            l2 = l2->next;
        }   
        else
        {
            head = l1;
            p = l1;
            l1 = l1->next;
        }
        
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val > l2->val)
            {
                p->next = l2;
                p = p->next;
                l2 = l2->next;
            }
            else
            {
                p->next = l1;
                p = p->next;
                l1 = l1->next;
            }
        }
        
        if (l1)
            p->next = l1;
        if (l2)
            p->next = l2;
        return head;
    }
};