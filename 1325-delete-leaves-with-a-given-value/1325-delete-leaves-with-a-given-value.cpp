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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root -> left ){//// Recursively remove target leaf nodes from left subtree
            root -> left =  removeLeafNodes(root -> left,  target);
        }
        if(root -> right ){// // Recursively remove target leaf nodes from right subtree
            root -> right =  removeLeafNodes(root -> right,  target);
        }
        if(root -> left == NULL && root -> right == NULL && root -> val  == target){
            return NULL;//// After removing children, check if current node
        // has become a leaf and its value is equal to target

        }
        return root;
    }
};