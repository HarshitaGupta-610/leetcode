class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;
        for (int x : nums) {
            total += x;
        }

        int r = total % p;
        if (r == 0){
            return 0;
        } 

        unordered_map<int, int> mp;
        mp[0] = -1;

        long long prefix = 0;
        int n = nums.size();
        int ans = n;

        for (int i = 0; i < n; i++) {
            prefix = (prefix + nums[i]) % p;

            int target = (prefix - r + p) % p; 

            if (mp.count(target)) {
                ans = min(ans, i - mp[target]);
            }

            mp[prefix] = i;
        }

        if(ans < n ){
            return ans;
        }
        else{
            return -1;
        }
    }
};
