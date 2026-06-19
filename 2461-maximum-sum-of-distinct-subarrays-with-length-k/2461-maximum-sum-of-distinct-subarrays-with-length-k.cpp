class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        unordered_set<int> st;
        long long sum = 0;
        long long ans = 0;

        int left = 0;

        for(int right = 0; right < nums.size(); right++) {

            while(st.find(nums[right]) != st.end()) {
                st.erase(nums[left]);
                sum -= nums[left];
                left++;
            }
            st.insert(nums[right]);
            sum += nums[right];

            if(st.size() == k) {
                ans = max(ans, sum);
                st.erase(nums[left]);
                sum -= nums[left];
                left++;
            }
        }

        return ans;
    }
};