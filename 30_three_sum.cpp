/**
 * Key Learning Point: Honestly this was pretty tough and I had to rely on neetcode to get the
 * solution. my initial thoughts was to use sets to keep track of what i have seen so far but it
 * wasnt very convenient/doable. this solution was smarter.
 *
 * it makes use of Two Sum II, which apparently uses L and R pointers within a sorted array. So the
 * general idea is after sorting the array, we want to skip triplets that start with the same number
 * that we have previously seen. so suppose we did for (1, -1, 0), if the next value was 1, we skip
 * it, since we would arrive at the same triplets.
 *
 * now 1st value is different, we are in the business of looking for our two sum. we cannot start
 * from ourselves, so we start from i + 1. sum bigger, decrement right, smaller, increment left. now
 * suppose we found our sum/triplet, we collect it. BUT the two sum does not stop there. because
 * there is chance that another possible solution can still exist within the window, so we basically
 * make it smaller until we encounter a unique 2nd position value. then we repeat two sum loop.
 *
 * this solution works because of sorting!
 *
 * Runtime: O(nlogn) + O(n^2) -> O(n^2). The O(n^2) is due to the window size. First window is n-1.
 * then n-2, then n-3. so arithmetic sum.
 *
 * Memory: O(1) or O(n) depending on sorting algorithm
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> output;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            // don't want to collect triplets that start with the same number
            // (1st position)
            if (i > 0 && nums[i - 1] == nums[i]) {
                continue;
            }

            int l = i + 1;
            int r = nums.size() - 1;
            // two sum search
            while (l < r) {
                if (nums[l] + nums[r] + nums[i] < 0) {
                    l++;
                    continue;
                }

                if (nums[l] + nums[r] + nums[i] > 0) {
                    r--;
                    continue;
                }

                output.push_back({nums[i], nums[l], nums[r]});
                l++;
                // we want to keep searching for valid pairs within the window
                // still this is akin to skipping values that share the same 2nd
                // position.
                while (nums[l] == nums[l - 1] && l < r) {
                    l++;
                }
            }
        }

        return output;
    }
};
