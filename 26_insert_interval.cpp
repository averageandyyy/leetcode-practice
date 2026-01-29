/**
 * Key Learning Point: This is a O(n) which is actually pretty easy to understand once we draw things out. I was trying to do some
 * binary search thing which actually complicated things. The idea: iterate through the list of intervals, if we have not added the new
 * interval yet, we check if there is an overlap. if there is overlap, we update the new interval and don't anything just yet. if there
 * is no overlap, we add the interval if it is smaller than the new interval, otherwise this is the right place to insert the new
 * interval and so we do that and also insert the current candidate interval, since it comes after the new interval.
 *
 * once we've added the new interval and the non-overlapping next interval, all subsequent intervals do not overlap and can be freely
 * inserted.
 *
 * because the array is sorted, the subsequent intervals either overlap or are bigger than the newInterval.
 *
 * sneaky edgecase where if the newInterval is not yet added, just throw it in. accounts for the empty and newInterval at the end case.
 *
 * Runtime: O(n)
 *
 * Memory: O(n)
 *
 */
class Solution {
public:
    bool doesOverlap(vector<int>& a, vector<int>& b) {
        return (a[0] >= b[0] && a[0] <= b[1]) ||
               (a[1] >= b[0] && a[1] <= b[1]) ||
               (b[0] >= a[0] && b[0] <= a[1]) || (b[1] >= a[0] && b[1] <= a[1]);
    }

    bool isSmaller(vector<int>& a, vector<int>& b) { return a[1] < b[0]; }

    bool isBigger(vector<int>& a, vector<int>& b) { return a[0] > b[1]; }

    vector<int> createNewInterval(vector<int>& a, vector<int>& b) {
        int smallest = (a[0] < b[0]) ? a[0] : b[0];
        int largest = (a[1] > b[1]) ? a[1] : b[1];

        return vector<int>{smallest, largest};
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        vector<vector<int>> output_intervals;
        bool newIntervalAdded = false;
        for (auto interval : intervals) {
            if (!newIntervalAdded) {
                if (!doesOverlap(interval, newInterval) &&
                    isSmaller(interval, newInterval)) {
                    output_intervals.push_back(interval);
                } else if (!doesOverlap(interval, newInterval) &&
                           isBigger(interval, newInterval)) {
                    output_intervals.push_back(newInterval);
                    output_intervals.push_back(interval);
                    newIntervalAdded = true;
                } else {
                    newInterval = createNewInterval(interval, newInterval);
                }
            } else {
                output_intervals.push_back(interval);
            }
        }

        if (!newIntervalAdded) {
            output_intervals.push_back(newInterval);
        }

        return output_intervals;
    }
};
