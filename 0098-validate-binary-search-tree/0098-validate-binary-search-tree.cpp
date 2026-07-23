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

    // minVal = minimum allowed value
    // maxVal = maximum allowed value
    bool check(TreeNode* root, long long minVal, long long maxVal){

        // Empty tree hamesha valid BST hoti hai
        if(root == NULL)
            return true;

        // Agar current node allowed range ke bahar hai
        if(root->val <= minVal || root->val >= maxVal)
            return false;

        // Left subtree check karo
        // Left ke saare nodes root se chote hone chahiye
        bool left = check(root->left, minVal, root->val);

        // Right subtree check karo
        // Right ke saare nodes root se bade hone chahiye
        bool right = check(root->right, root->val, maxVal);

        // Dono valid hone chahiye
        return left && right;
    }

    bool isValidBST(TreeNode* root) {

        // Initially koi restriction nahi hai
        return check(root, LLONG_MIN, LLONG_MAX);
    }
};