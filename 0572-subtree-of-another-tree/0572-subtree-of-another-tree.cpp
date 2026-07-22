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

    bool isSameTree(TreeNode* root1, TreeNode* root2){

        // Dono NULL hain
        if(root1 == NULL && root2 == NULL)
            return true;

        // Ek NULL hai, ek nahi
        if(root1 == NULL || root2 == NULL)
            return false;

        // Values alag hain
        if(root1->val != root2->val)
            return false;

        // Left aur Right subtree compare karo
        return isSameTree(root1->left, root2->left) &&
               isSameTree(root1->right, root2->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        // Main tree khatam ho gayi
        if(root == NULL)
            return false;

        // Current node se subtree match ho gayi
        if(isSameTree(root, subRoot))
            return true;

        // Left ya Right subtree mein search karo
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};