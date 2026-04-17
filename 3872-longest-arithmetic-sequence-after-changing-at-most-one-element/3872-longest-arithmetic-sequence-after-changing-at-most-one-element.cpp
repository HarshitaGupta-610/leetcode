class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return n;
        }

        vector<int> rlen(n), llen(n);
        rlen[0] = 1; rlen[1] = 2;
        for (int i = 2; i < n; i++)
            rlen[i] = ((long long)nums[i]-nums[i-1] == (long long)nums[i-1]-nums[i-2])
                      ? rlen[i-1]+1 : 2;

        llen[n-1] = 1; llen[n-2] = 2;
        for (int i = n-3; i >= 0; i--)
            llen[i] = ((long long)nums[i+1]-nums[i] == (long long)nums[i+2]-nums[i+1])
                      ? llen[i+1]+1 : 2;

        int ans = 2;

        // Case 1: adjacent anchor (i, i+1), 1 change outside the runs
        for (int i = 0; i+1 < n; i++) {
            long long d = (long long)nums[i+1] - nums[i];
            int L = (i >= 1 && (long long)nums[i]-nums[i-1] == d) ? rlen[i] : 1;
            int R = (i+2 < n && (long long)nums[i+2]-nums[i+1] == d) ? llen[i+1] : 1;
            ans = max(ans, min(n, L + R + 1));
        }

        // Case 2: anchor (i, i+2), 1 change at middle position i+1
        for (int i = 0; i+2 < n; i++) {
            long long gap = (long long)nums[i+2] - nums[i];
            if (gap % 2 != 0) continue;
            long long d = gap / 2;
            int L = (i >= 1 && (long long)nums[i]-nums[i-1] == d) ? rlen[i] : 1;
            int R = (i+3 < n && (long long)nums[i+3]-nums[i+2] == d) ? llen[i+2] : 1;
            ans = max(ans, min(n, L + 1 + R));
        }

        return ans;
    }
};