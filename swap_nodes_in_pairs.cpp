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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
            
        ListNode* a = head;
        ListNode* b = a->next;
        head = b;
        ListNode* tmp = b->next;
        while (a != nullptr && b != nullptr)
        {
            b->next = a;
            if (tmp != nullptr)
            {
                if (tmp->next == nullptr)
                {
                    a->next = tmp;
                    break;
                }
                else
                    a->next = tmp->next;
            }
            else
            {
                a->next = tmp;
                break;
            }
            
            a = tmp;
            b = tmp->next;
            tmp = b->next;
        }
        return head;
    }
};