/**
 * Key Learning Point: For a palindrome, just collect/+2 whenever you see a pair. A palindrome in general can only consist of pairs and
 * a singular central character, which is optional. So then the idea is, as you iterate over the string, you track the pairs and +2
 * everytime you see them, because you want these pairs. If you somehow have odd frequencies, regardless, you can take as many pairs as
 * you can from them until you are left with just 1 character. This can happen for all the odd frequency characters. At that point, it
 * doesn't matter which character you pick, because they are all singular count.
 *
 * so collect pairs and +2, if there are singles remaining, pick any one.
 *
 * Runtime: O(n)
 *
 * Memory: O(1) at most 52 characters.
 *
 */
class Solution {
public:
    int longestPalindrome(string s) {
     unordered_set<char> seen;
     int output = 0;
     for (char c : s)
     {
        if (seen.find(c) != seen.end())
        {
            seen.erase(c);
            output += 2;
        }
        else
        {
            seen.insert(c);
        }
     }

     if (!seen.empty())
     {
        output += 1;
     }
     
     return output;
    }
};
