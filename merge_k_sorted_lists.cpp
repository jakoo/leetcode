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
    class StoreUnit {
    public:    
        ListNode* node;
        int index;
        
        StoreUnit(ListNode* node, int index) : node(node), index(index) {};
        
        bool operator< (const StoreUnit& b) const
        {
            return node->val < b.node->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        multiset<StoreUnit> rbtree;
        bool valid = false;
        for(int i = 0; i < lists.size(); ++i)
        {
            if (lists[i] != nullptr)
            {
                valid = true;
                rbtree.insert(StoreUnit(lists[i], i));
                lists[i] = lists[i]->next;
            }
        }
        
        if (lists.size() == 0 || !valid)
            return nullptr;
            
        auto smallest = rbtree.begin();
        ListNode* head = smallest->node;
        ListNode* curr = head;
        int index = smallest->index;
        rbtree.erase(smallest);
        if (lists[index] != nullptr)
        {
            rbtree.insert(StoreUnit(lists[index], index));
            lists[index] = lists[index]->next;
        }
        
        while (!rbtree.empty())
        {
            auto smallest = rbtree.begin();
            curr->next = smallest->node;
            curr = curr->next;
            int index = smallest->index;
            rbtree.erase(smallest);
            if (lists[index] != nullptr)
            {
                rbtree.insert(StoreUnit(lists[index], index));
                lists[index] = lists[index]->next;
            }
        }
        
        return head;
    }
};