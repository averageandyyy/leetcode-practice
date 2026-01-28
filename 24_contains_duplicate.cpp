/**
 * Key Learning Point: unordered_set being unordered, uses hash table underneath, so insertion, deletion and search are O(1) on average
 * (worst is still O(n) if many collisions). set on the other hand being ordered, has O(logn) for these operations instead.
 *
 * Runtime: O(n)
 *
 * Memory: O(n)
 */
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for (int i : nums)
        {
            if (seen.find(i) != seen.end())
            {
                return true;
            }

            seen.insert(i);
        }

        return false;
    }
};
