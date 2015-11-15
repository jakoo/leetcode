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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 1)
            return head;
        
        ListNode* one = head;
        ListNode* oneBackup = one;
        ListNode* two = one->next;
        ListNode* three = two->next;
        ListNode* nextHead = exist(one, k);
        
        if (nextHead)
            head = nextHead;
        else
            return head;

        while (1)
        {
            bool end = false;
            
            ListNode* nextHead = exist(one, 2 * k);
            if (nextHead)
                one->next = nextHead;
            else
                end = true;
                
            for(int i = 0; i < k - 2; ++i)
            {
                two->next = one;
                one = two;
                two = three;
                three = three->next;
            }
            two->next = one;
            
            if (end)
            {
                oneBackup->next = three;
                break;
            }
            
            one = oneBackup = three;
            two = one->next;
            three = two->next;
        }
        return head;
    }
    
    ListNode* exist(ListNode* head, int k)
    {
        for(int i = 0; i < k - 1; ++i)
        {
            if (head == nullptr)
            {
                return nullptr;
            }
            head = head->next;
        }
        return head;
    }
};