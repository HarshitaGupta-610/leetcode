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
    int maxDepth(TreeNode* root) {
if(root == NULL) {
            return 0;
        }


//         //1.Approach;
//         // BFS (Level Order Traversal) , number of levels = depth
//         queue<TreeNode*> q;
//         // Traversal root node se start hoga.
//         q.push(root);
//  // Ye variable final maximum depth store karega.
//         int depth = 0;
//         // Jab tak queue empty nahi hoti,
//         // tab tak tree me nodes bache hue hain.
//         while(!q.empty()) {
//             // Queue me iss time jitne nodes hain,
//             // woh saare ek hi level ke belong karte hain.
//             //
//             // Example:
//             //
//             //        1
//             //       / \
//             //      2   3
//             //
//             // Queue = [2,3]
//             // size = 2
//             //
//             // Matlab current level me 2 nodes hain.
//             int size = q.size();

//             // Ab current level ke saare nodes process karenge.
//             while(size--) {

//                 // Queue ka front node uthao.
//                 TreeNode* node = q.front();

//                 // Us node ko queue se hata do.
//                 q.pop();

//                 // Agar left child exist karta hai,
//                 // to use queue me daal do.
//                 //
//                 // Ye current level ka part nahi hai,
//                 // ye NEXT level ka node hai.
//                 if(node->left != NULL) {
//                     q.push(node->left);
//                 }

//                 // Agar right child exist karta hai,
//                 // to use bhi queue me daal do.
//                 if(node->right != NULL) {
//                     q.push(node->right);
//                 }
//             }
//             // Jab inner while loop khatam ho gaya,
//             // iska matlab current level ke SAARE nodes visit ho gaye.
//             // Isliye ek complete level finish hua.
//             depth++;
//         }

//         // Queue empty ho gayi.
//         // Matlab saare levels traverse ho chuke hain.
//         return depth;



//2.Recursive DFS
// Left subtree ki maximum depth nikaalo.
        int leftDepth = maxDepth(root->left);

        // Right subtree ki maximum depth nikaalo.
        int rightDepth = maxDepth(root->right);

        // ---------------- Current Node ----------------
        // Current node ki depth hogi:
        //
        // 1 (current node)
        // +
        // max(left subtree depth, right subtree depth)
        //
        // Hum maximum isliye lete hain kyunki
        // question longest root-to-leaf path pooch raha hai.
        return 1 + max(leftDepth, rightDepth);
    }
};