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
    pair<int, TreeNode*> dfs(TreeNode* root){
        if(root == NULL){
            return {0, nullptr};
        }
        pair<int, TreeNode*> left = dfs(root->left);
        pair<int, TreeNode*> right = dfs(root->right);
        int leftHeight= left.first;
        int rightHeight = right.first;
        if(leftHeight==rightHeight){
            return {leftHeight+1, root};
        }
        else if(leftHeight > rightHeight){
            return {leftHeight+1, left.second};
        }
        else{
            return {rightHeight+1, right.second};
        }
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        pair<int, TreeNode*> ans = dfs(root);
        return ans.second;
    }
};