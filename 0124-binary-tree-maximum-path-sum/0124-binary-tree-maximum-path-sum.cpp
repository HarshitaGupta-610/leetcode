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

        /*
        At every node, there are two questions.
        1,If the best path ends at me, what is its value
        2.If my parent wants to continue through me, what can I offer
        Main apne liye dono bachchon ko use kar sakta hoon (ans update karne ke liye), lekin apne parent ko sirf ek hi bachcha de sakta hoon (return karne ke liye)
        */
//ans = max(ans, left + right + root->val);
// Ye problem ka answer maintain kar rahi hai
// return root->val + max(left,right);
// Ye sirf parent ko information de raha hai.

// We don't return left + right + root because it forms a branch. A parent can continue the path through only one child, so we return root + max(left, right) instead.
 class Solution {
public:
//Recursive DFS : O(N) where n is nodes number
    int ans = INT_MIN;

    int dfs(TreeNode* root) {

        // Agar node NULL hai to koi path nahi hai to sum mein 0 add
        if(root == NULL) {
            return 0;
        }
// negative path ko include karne se path sum aur kam ho jayega, aur hume maximum path sum chahiye so 0 aur positive mein compare karo
        // Left subtree ka maximum gain. , 
        int left = max(0, dfs(root->left));

        // Right subtree ka maximum gain.
        int right = max(0, dfs(root->right));

        // =======================
        // JOB 1 (For Myself)
        // =======================
        // Socho current node hi maximum path ka peak hai.
        // To left + root + right ek complete path banegi.
        int currPath = left + right + root->val;

        // Pure tree ka best answer update karo.
        ans = max(ans, currPath);

        // =======================
        // JOB 2 (For Parent)
        // =======================
        // Parent ko sirf ek hi side de sakte hain.
        // Dono sides denge to branch ban jayegi, path nahi.
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {

        dfs(root);

        return ans;
    }
};