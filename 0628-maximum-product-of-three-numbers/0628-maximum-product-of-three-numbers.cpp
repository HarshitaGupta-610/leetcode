class Solution {
public:
    int maximumProduct(vector<int>& nums) {
       sort(nums.rbegin() , nums.rend());
       int n = nums.size();
       int p1 = nums[0]*nums[1]*nums[2];
       int p2 = nums[n-1]*nums[n-2]*nums[0];
       return (max(p1,p2));
    }
};