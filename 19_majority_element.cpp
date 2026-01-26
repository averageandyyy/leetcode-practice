/**
 * Key Learning Point: Boyer-Moore Algorithm. No proof for this but the idea is that given an input with a majority element, that is,
 * it appears more than floor(n / 2) times, the following algorithm below will work. Increment if same as the number you last saw/are
 * going to return and decrement otherwise. If 0, update the to be returned number and increment. Can think of the eventual count as
 * how many more times does the most common value appear more than the next most common value. Actually that's not true either. Guess
 * it just works.
 *
 * The alternative is hashmap and count occurences.
 *
 * Runtime: O(n)
 *
 * Memory: O(1)
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int output = 0;
        int count = 0;

        for (int i : nums)
        {
            if (count == 0 || i == output)
            {
                count++;
                output = i;
            }
            else if (i != output)
            {
                count--;
            }
        }

        return output;
    }
};
