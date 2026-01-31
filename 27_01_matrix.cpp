/**
 * Key Learning Point: We first keep track of the 0s that we see and also add an identifier to those that require updating (-1). Based
 * on our initial queue of 0s, we check if they have neighbors that require an update i.e. valued at -1. These updated neighbors are
 * also added to the queue, since they can have neighbors that require updates, which are also just 1-hop away. Pretty smart solution.
 * My initial solution which led to time-exceeded was some DFS.
 *
 * Runtime: O(n) only as worse as the number of elements in matrix
 *
 * Memory: O(n) in creating the queue as well, upper bounded by the number of elements in matrix.
 *
 * Also learnt that to iterate and append over the same vector, must use indexed based, cannot use auto iteration.
 */
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<pair<int, int>> queue;
        vector<pair<int, int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 0) {
                    queue.push_back({i, j});
                } else {
                    mat[i][j] = -1;
                }
            }
        }

        for (int i = 0; i < queue.size();
             i++) // Cannot use iterator based if we are appending to the queue
        {
            for (auto direction : directions) {
                auto location = queue[i];
                int new_row = location.first + direction.first;
                int new_col = location.second + direction.second;

                if (new_row >= 0 && new_row < mat.size() && new_col >= 0 &&
                    new_col < mat[0].size() && mat[new_row][new_col] == -1) {
                    // This is key. Notice that we only update our -1s, and we
                    // also consider contributions from the queue
                    mat[new_row][new_col] =
                        mat[location.first][location.second] + 1;
                    queue.push_back({new_row, new_col});
                }
            }
        }

        return mat;
    }
};
