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
//Time Complexity: O(n) kyunki har node ko sirf ek baar visit (pop/process) karte hain.
    vector<vector<int>> levelOrder(TreeNode* root) {
vector<vector<int>>a;
if(root ==NULL){
    return a;
}// koi tree nahi hai koi ans nahi
    /*"I visit one node, then I put its children in the queue. Then I visit those children one by one, and each of them puts their own children into the queue."*/
    //Queue mein root daalo, phir jab bhi koi node bahar nikalo (pop), uske left aur right children ko queue mein daal do; ye process queue khali hone tak repeat karo."
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int>level;
        while(size--){//Current level mein total kitne nodes hain
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);
            if(node -> left != NULL) q.push(node->left);
            if(node -> right != NULL) q.push(node->right);
        }
        a.push_back(level);//size 0 matlab level processed
    }
    return a;
    }
};