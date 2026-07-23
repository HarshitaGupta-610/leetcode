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

    // Value -> Index in inorder
    unordered_map<int,int> m;

    // Postorder ka current root index
    int index;

    TreeNode* build(vector<int>& inorder,vector<int>& postorder,int left,int right)
    {
        // Agar range invalid ho gayi to koi node nahi bachi
        if(left > right)return NULL;

        // Postorder ke current element se root banao
        TreeNode* root = new TreeNode(postorder[index]);

        // Root use ho gaya, index ek peeche le jao
        index--;

        // Root ki position inorder mein nikalo
        int pos = m[root->val];

        // Pehle Right subtree banao
        root->right = build(inorder, postorder, pos + 1, right);

        // Fir Left subtree banao
        root->left = build(inorder, postorder, left, pos - 1);

        // Current subtree return karo
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        // Inorder ki value aur index map mein store karo
        for(int i = 0; i < inorder.size(); i++)
            m[inorder[i]] = i;

        // Postorder ke last index se start karenge
        index = postorder.size() - 1;

        // Puri tree build karo
        return build(inorder, postorder, 0, inorder.size() - 1);
    }
};