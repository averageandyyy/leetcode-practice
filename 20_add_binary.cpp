/**
 * Key Learning Point: Insert is O(1) operation. If we keep inserting, it ends up being 1 + 2 + ... +
 * (n+m) = O((n+m)^2). Reversing is just a simple O(n + m), so that is better. Regular binary logic.
 *
 * Runtime: O(n+m) the two strings
 *
 * Memory: O(n+m). the `remainder` is at max(n, m), which is lesser than O(n + m).
 */
class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        string output;
        while (a.length() && b.length())
        {
            if (carry)
            {
                if (a.at(a.length() - 1) == '1')
                {
                    a.at(a.length() - 1) = '0';
                }
                else
                {
                    a.at(a.length() - 1) = '1';
                    carry = 0;
                }
            }

            if (a.at(a.length() - 1) == '1' && b.at(b.length() - 1) == '1')
            {
                output += '0';
                carry = 1;
            }
            else if (a.at(a.length() - 1) == '0' && b.at(b.length() - 1) == '0')
            {
                output += '0';
            }
            else
            {
                output += '1';
            }

            a.erase(a.length() - 1);
            b.erase(b.length() - 1);
        }

        string remainder = a.length() ? a : b;

        while (remainder.length())
        {
            if (carry)
            {
                if (remainder.at(remainder.length() - 1) == '1')
                {
                    remainder.at(remainder.length() - 1) = '0';
                }
                else
                {
                    remainder.at(remainder.length() - 1) = '1';
                    carry = 0;
                }
            }

            output += remainder.at(remainder.length() - 1);
            remainder.erase(remainder.length() - 1);
        }

        if (carry)
        {
            output += '1';
        }
        reverse(output.begin(), output.end());
        return output;
    }
};
