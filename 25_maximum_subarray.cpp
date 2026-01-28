/**
 * Key Learning Point: Kadane's Algorithm. Positive values/sum we keep going. but if our sum is negative consider this: encounter 0->0
 * is better, encounter positive->positive is better, encounter negative->don't add to make things worse. in any case, if our sum is
 * negative, we stop expanding the subarray or reset, because we can always do better from there.
 *
 * Runtime: O(n)
 * Memory: O(1)
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int largest_sum = INT_MIN;
        for (int i : nums)
        {
            sum += i;
            largest_sum = (sum > largest_sum) ? sum : largest_sum;
            sum = (sum < 0) ? 0 : sum; 
        }

        return largest_sum;
    }
};
