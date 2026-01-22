/**
 * Key Learning Point: Recursion! The first (newest solution) used recursion but its not as elegant
 * as the second solution. Good job old me!
 *
 * Runtime: O(mxn) rows by columns
 *
 * Memory: O(1)
 */
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int original = image[sr][sc];
        if (original == color)
        {
            return image;
        }
        image[sr][sc] = color;

        if (sr + 1 < image.size())
        {
            if (image[sr + 1][sc] == original)
            {
                floodFill(image, sr + 1, sc, color);
            }
        }

        if (sr - 1 >= 0)
        {
            if (image[sr - 1][sc] == original)
            {
                floodFill(image, sr - 1, sc, color);
            }
        }

        if (sc + 1 < image[0].size())
        {
            if (image[sr][sc + 1] == original)
            {
                floodFill(image, sr, sc + 1, color);
            }
        }

        if (sc - 1 >= 0)
        {
            if (image[sr][sc - 1] == original)
            {
                floodFill(image, sr, sc - 1, color);
            }
        }

        return image;
    }
};
