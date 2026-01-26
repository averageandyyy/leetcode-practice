/**
 * Key Learning Point: Use global variable to maintain diameter. diameterUpdate represents the candidate diameter if we were to go
 * through the current node, which is just the sum of the two subtree heights.
 *
 * tldr; diameter through a current node is just the sum of heights of its subtrees. then we update if we do better.
 *
 * Runtime: O(n) go through every node
 *
 * Memory: O(h) height of recursive callstack
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
    int diameter = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);

        return diameter;
    }

    int height(TreeNode* root)
    {
        if (!root)
        {
            return 0;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        int heightToReturn = (leftHeight > rightHeight) ? leftHeight : rightHeight;
        heightToReturn += 1;

        int diameterUpdate = leftHeight + rightHeight; // diameter if we go through current node
        diameter = (diameterUpdate > diameter) ? diameterUpdate : diameter;

        return heightToReturn;
    }
};
