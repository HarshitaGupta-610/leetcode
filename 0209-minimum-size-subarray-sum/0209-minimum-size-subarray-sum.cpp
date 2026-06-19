class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int mini = INT_MAX;;
        int n = nums.size();
        int l = 0;
        int sum = 0;
        for(int  r = 0 ; r < n ; r++){
            sum += nums[r];
            while(sum >= target){
             mini = min(mini , r - l +1);
             sum -= nums[l];
             l++;
            }
        }
        if(mini != INT_MAX){
            return mini;
        }
        return 0;
    }
};