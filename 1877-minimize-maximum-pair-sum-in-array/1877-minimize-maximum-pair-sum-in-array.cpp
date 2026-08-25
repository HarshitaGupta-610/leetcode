class Solution {
public:
    int minPairSum(vector<int>& nums) {
      sort(nums.begin() , nums.end());
      int n = nums.size();
      int ans = 0;
      for(int i = 0 ; i < nums.size() ; i++){
        ans = max(ans , nums[n-1-i] + nums[i]);
      }  
      return ans;
    }
};