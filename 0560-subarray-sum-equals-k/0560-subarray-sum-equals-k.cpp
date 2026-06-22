class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = 1;

        int currSum = 0;
        int ans = 0;

        for(int x : nums) {
            currSum += x;
            ans += m[currSum - k];
            m[currSum]++;
        }

        return ans;
    }
};