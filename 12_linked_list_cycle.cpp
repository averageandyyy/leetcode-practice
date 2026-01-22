/**
 * Key Learning Point: Tortoise and Hare. Either the fast pointer will catch up to the slow pointer
 * or the fast pointer will see nullptr first. In every iteration of the loop, the distance between
 * the fast and slow pointer is reduced by 1: x = x + 1 - 2. At worst, the gap is n - 1 (f is 1 ahead
 * of s).
 *
 * Runtime: O(n)
 *
 * Memory: O(1)
 */

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
    bool hasCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast && slow)
        {
            if (fast->next && fast->next->next)
            {
                fast = fast->next->next;
            }
            else
            {
                return false;
            }

            if (slow->next)
            {
                slow = slow->next;
            }

            if (slow == fast)
            {
                return true;
            }
        }

        return false;
    }
};
