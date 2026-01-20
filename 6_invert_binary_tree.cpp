/**
 * Key Learning Point: Recall that every child of a tree node is another tree/tree node. i.e. The operation/work done on a tree 
 * can and should be applied the same way to subtree. This screams recursive!
 *
 * Memory: O(1)
 * 
 * Runtime: O(n)
 *
 * This solution was pure instinct. I actually did not properly understand what the question was asking for nor what property
 * of the tree I should have been using so I just pattern-recognitioned and saw that they just kept swapping recursively.
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
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
        {
            return root;
        }

        TreeNode* temp = nullptr;
        temp = root->left;
        root->left = root->right;
        root->right = temp;

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};
