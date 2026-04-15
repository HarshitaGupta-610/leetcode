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
    int remaining; 
    int answer;

    void inorder(TreeNode* root) {
        if (root == NULL || remaining == 0) {
            return;
        }

        inorder(root->left);

        remaining--;
        if (remaining == 0) {     
            answer = root->val;
            return;
        }

        inorder(root->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        remaining = k;
        inorder(root);
        return answer;
    }
};
