/**
 * Key Learning Point: Sliding Window! Knowing when to truncate the window from the front and to
 * extend was crucial. If it's something we've seen before truncate the window until we've basically
 * lost the old character that was messing with us. At this point, we can continue extending the
 * window and checking for lengths.
 *
 * Runtime: O(n), go through the string once
 *
 * Memory: O(n), set can have as many characters as the string
 *
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int end = 1;
        int longest = 0;
        unordered_set<char> seen;
        if (!s.empty()) { // edge case
            seen.insert(s[start]);
        }
        while (end < s.size() && start <= end) {
            if (seen.find(s[end]) != seen.end()) // we saw this before
            {
                seen.erase(s[start]); // this is effectively truncating our
                                      // substring from the start
                start++;
                continue;
            }

            // new character, add to seen, extend window
            seen.insert(s[end]);
            end++;

            longest = longest > seen.size() ? longest : seen.size(); // update longest
        }

        return longest > seen.size() ? longest : seen.size();
    }
};
