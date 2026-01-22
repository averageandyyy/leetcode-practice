/**
 * Key Learning Point: Used recursion and an indicator of -1 to know if unbalanced. Tree is overall
 * unbalanced if any of its subtrees are unbalanced. Balanced means the difference in height between
 * subtrees is at most 1. Run recursion to check height/balancedness of subtrees. If both balanced,
 * then own height is maximum of the two plus 1.
 *
 * Happy because I worked this out lol.
 *
 * Runtime: O(n) visit every node
 *
 * Memory: O(1)
 *
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int isBalancedWithHeight(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        int leftHeight = isBalancedWithHeight(root->left);
        int rightHeight = isBalancedWithHeight(root->right);

        if ((leftHeight == -1) || (rightHeight == -1) || (abs(leftHeight - rightHeight) > 1))
        {
            return -1;
        }

        int height = max(leftHeight, rightHeight) + 1;

        return height;
    }

    bool isBalanced(TreeNode* root) {
        return isBalancedWithHeight(root) != -1;
    }
};
