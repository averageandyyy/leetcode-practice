/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/**
 * Key Learning Point: Used recursion, can also be done iteratively. Care about what we return/pick. Sorry future me this
 * is not a good explaination but i think this question was rather straighforward
 * 
 * Runtime: O(n)
 *
 * Memory: O(1)
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 || !list2)
        {
            return list1 ? list1 : list2;
        }

        ListNode* current = nullptr;
        
        if (list1->val < list2->val)
        {
            current = list1;
            list1 = list1->next;
        }
        else
        {
            current = list2;
            list2 = list2->next;
        }

        current->next = mergeTwoLists(list1, list2);

        return current;
    }
};
