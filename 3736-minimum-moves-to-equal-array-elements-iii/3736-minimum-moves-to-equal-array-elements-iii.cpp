class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        int maxi = nums[n-1];
        int sum = 0;
        for(int i = 0 ; i < n-1 ; i++){
            sum += maxi - nums[i];
        }
        return sum;
    }
};