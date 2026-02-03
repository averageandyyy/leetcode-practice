/**
 * Key Learning Point: Use maxheap and iterate + push/pop from array. Doesn't matter what we push,
 * but since its maxheap, we always pop the biggest element, which always leaves us with smaller
 * elements, exactly what we want.
 *
 * Runtime: O(NlogK). every push/pop is at best logK, and we do it N times.
 *
 * Memory: O(K)
 *
 * my first implementation was less efficient because it involved converting the entire vector in a
 * heap which is either O(N) or O(NlogN)
 */
class Solution {
public:
    static int distance(const vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1];
    }

    static bool smaller_than(const vector<int>& a, const vector<int>& b) {
        return distance(a) < distance(b);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> output;
        output.reserve(k);
        for (int i = 0; i < points.size(); i++) {
            output.push_back(points[i]);
            // underlying implementation is max heap. the comparator (in
            // general) if element a is lesser than b. we always pop the biggest
            // element, since we only want small ones
            push_heap(output.begin(), output.end(), smaller_than);

            if (output.size() > k) {
                pop_heap(output.begin(), output.end(), smaller_than);
                output.pop_back();
            }
        }
        return output;
    }
};

class Solution {
public:
    static int distance(const vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1];
    }

    static bool smaller_than(const vector<int>& a, const vector<int>& b) {
        return distance(a) > distance(b);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> output;
        output.reserve(k);
        make_heap(points.begin(), points.end(), smaller_than);
        for (int i = 0; i < k && !points.empty(); i++) {
            output.push_back(points[0]);
            pop_heap(points.begin(), points.end(), smaller_than);
            points.pop_back();
        }
        return output;
    }
};
