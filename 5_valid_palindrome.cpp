/**
 * Key Learning Point: Two pointer solution! The key thing about our solution is that it
 * is O(1) memory. No need to create new filtered string. Small note that L >= R is also valid. So
 * actually can just return true at the end.
 * Consider "aa"!
 *
 * Memory: O(1)
 *
 * Runtime: O(n)
 */
class Solution {
public:
    bool isPalindrome(string s) {
        int start_index = 0;
        int end_index = s.length() - 1;

        while (start_index < end_index)
        {
            char start_char = s.at(start_index);
            char end_char = s.at(end_index);

            // Check for alphanumeric, if not, we skip
            if (!isalnum(start_char))
            {
                start_index += 1;
                continue;
            }

            if (!isalnum(end_char))
            {
                end_index -= 1;
                continue;
            }

            // Alphanumeric, check for sameness
            if (!(tolower(start_char) == tolower(end_char)))
            {
                return false;
            }

            start_index += 1;
            end_index -= 1;
        }

        return start_index >= end_index;
    }
};
