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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p = NULL, *head = NULL;

        int carry = 0;
        int next_carry = 0;
        int val = 0;

        if (l1 && l2)
        {
            val = l1->val + l2->val;
            if (val >= 10)
            {
                val -= 10;
                next_carry = 1;
            }
            else
                next_carry = 0;
            head = new ListNode(val);
            l1 = l1->next;
            l2 = l2->next;
            p = head;
        }

        while (l1 && l2)
        {
            val = l1->val + l2->val + next_carry;
            if (val >= 10)
            {
                val -= 10;
                next_carry = 1;
            }
            else
                next_carry = 0;
            ListNode *temp = new ListNode(val);
            l1 = l1->next;
            l2 = l2->next;
            p->next = temp;
            p = temp;
        }

        if (l1)
        {
            if (!p)
                head = l1;
            else
            {
                while(l1)
                {
                    val = l1->val + next_carry;
                    if (val >= 10)
                    {
                        val -= 10;
                        next_carry = 1;
                    }
                    else
                        next_carry = 0;
                    p->next = new ListNode(val);
                    p = p->next;
                    l1 = l1->next;
                }
            }
        }
        else if (l2)
        {
            if (!p)
                head = l2;
            else
            {
                while(l2)
                {
                    val = l2->val + next_carry;
                    if (val >= 10)
                    {
                        val -= 10;
                        next_carry = 1;
                    }
                    else
                        next_carry = 0;
                    p->next = new ListNode(val);
                    p = p->next;
                    l2 = l2->next;
                }
            }
        }
        if (next_carry)
            p->next = new ListNode(next_carry);

        return head;
    }
};
