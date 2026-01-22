/**
 * Key Learning Point: This is basically just understanding how to algorithm works. Coding it out is
 * easy once you spot the trick. A node is LCA if it forces a split, that is, the nodes of interest
 * sit in the left and right subtree of the current node.
 *
 * A node is always the LCA of itself.
 *
 * If both nodes are greater than the node of interest, then the LCA lies in the right subtree and
 * vice versa.
 *
 * Runtime: O(logn) aka the height of the tree
 *
 * Memory: O(1)
 */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Self is always lowest common ancestor
        if ((root->val == p->val) || (root->val == q->val))
        {
            return root;
        }

        // We know that root is a common ancestor if it forces a split
        // that is, p and q sit in the left and right subtrees.
        if ((p-> val < root->val && q->val > root->val) || (p->val > root->val && q->val < root->val))
        {
            return root;
        }

        if (p-> val > root->val && q->val > root->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }

        return lowestCommonAncestor(root->left, p, q);
    }
};
