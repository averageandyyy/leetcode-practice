/**
 * Key Learning Point: Basic Binary Search! Bounds checking. To prevent overflow, we can instead do
 * mid = low + (high - low) / 2
 *
 * Memory: O(1)
 *
 * Runtime: O(logn)
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
   

        while (low <= high)
        {
            int mid = (high + low) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }

            if (nums[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        } 

        return -1;
    }
};
