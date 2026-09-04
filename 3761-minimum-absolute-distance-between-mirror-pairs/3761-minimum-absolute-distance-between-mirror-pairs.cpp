class Solution {
public:
    int reverse(int n) {
        int ans = 0;
        while(n) {
            int digit = n % 10;
            ans = ans * 10 + digit;
            n /= 10;
        }
        return ans;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> m;
        int ans = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            int rev = reverse(nums[i]);
            // Previous number's reverse == current number
            if(m.count(nums[i])) {
                ans = min(ans, i - m[nums[i]]);
            }
            // Store reverse of current number
            m[rev] = i;
        }

        return (ans == INT_MAX ? -1 : ans);
    }
};