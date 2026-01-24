/**
 * Key Learning Point: Similar problem to anagrams! Use hashmap.
 *
 * Memory: O(n)
 *
 * Runtime: O(n)
 */
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
       unordered_map<char, int> counts;

       for (char c : magazine)
       {
         counts[c]++;
       }

       for (char c : ransomNote)
       {
        counts[c]--;
        if (counts[c] < 0)
        {
            return false;
        }
       }

       return true;
    }
};
