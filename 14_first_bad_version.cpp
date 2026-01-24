/**
 * Key Learning Point: Binary search and proper bounds.
 *
 * Runtime: O(logn)
 *
 * Memory: O(1)
 */
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1;
        int high = n;

        while (low <= high && high >= 1 && low <= n)
        {
            int mid = low + (high - low) / 2;
            if (isBadVersion(mid) && !isBadVersion(mid - 1))
            {
                return mid;
            }

            if (isBadVersion(mid))
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return n;
    }
};

// Cleaner
class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1;
        int high = n;

        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (!isBadVersion(mid))
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }

        return low;
    }
};
