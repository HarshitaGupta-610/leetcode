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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 * };
 */

class Solution {
public:

    int count = 0;
    int ans = 0;

    void dfs(TreeNode* root, int k){

        if(root == NULL)
            return;

        // Left subtree
        dfs(root->left, k);

        // Current node visit
        count++;

        // Agar k-th node mil gaya
        if(count == k){
            ans = root->val;
            return;
        }

        // Right subtree
        dfs(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {

        dfs(root, k);

        return ans;
    }
};