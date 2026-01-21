/**
 * Key Learning Point: Using hashmaps to check number of unique occurences of letters
 *
 * Memory: O(1) because finitely many number of entries in hashmap
 *
 * Runtime: O(n) iterate through both strings
 */
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> counts;

        for (char c : s)
        {
            counts[c]++;
        }

        for (char c : t)
        {
            counts[c]--;
            if (counts[c] < 0)
            {
                return false;
            }
        }

        for (auto count : counts)
        {
            if (count.second != 0)
            {
                return false;
            }
        }

        return true;
    }
};
