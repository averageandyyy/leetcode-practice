/*
 * Key Learning Point: use index: value hashmap for quick lookup
 * since there is only 1 value of interest per number.
 * Lookup is O(1). Array iterations is O(n). Overall O(n).
 * Memory is O(n)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Use unordered_map, key is numeric value, value is index
        std::unordered_map<int, int> hash;
        vector<int> output;
        for (int i = 0; i < nums.size(); i++)
        {
            int desired = target - nums[i];

            auto it = hash.find(desired);

            if (it != hash.end())
            {
                output.push_back(i);
                output.push_back(it->second);
                return output;
            }
            hash.insert({nums[i], i});
        }

        return output;
    }
};
