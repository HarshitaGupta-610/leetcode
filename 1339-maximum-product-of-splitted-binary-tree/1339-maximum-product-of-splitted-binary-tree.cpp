class Solution {
public:
    long long sum = 0;
    long long ans =INT_MIN;
    const int mod = 1e9 + 7;

    long long dfs(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        long long left = dfs(root->left);
        long long right = dfs(root->right);

        long long thisSum = left + right + root->val;

        ans = max(ans, thisSum * (sum - thisSum));
        return thisSum;
    }

    int maxProduct(TreeNode* root) {
        sum = dfs(root);
 dfs(root);

        return ans % mod;
    }
};
