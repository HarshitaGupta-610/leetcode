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
    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int ans = 1 + max(height(root->left), height(root->right));
        return ans;
    }

    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        }

        int LeftHeight = height(root->left);
        int RightHeight = height(root->right);

        if (abs(LeftHeight - RightHeight) > 1) {
            return false;
        }

        bool leftBalanced = isBalanced(root->left);
        bool rightBalanced = isBalanced(root->right);

        return leftBalanced && rightBalanced;
    }
};