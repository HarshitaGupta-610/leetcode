class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if( k == 1){
            return 0;
        }
        int n = nums.size();
        int mini = INT_MAX;
        sort(nums.begin() , nums.end());
        int len = k-1;
        for(int i = 0 ;( i < n && ( len < n)) ; i++){
         mini = min(mini , nums[ i + k-1] - nums[i]);
         len++;
        }
        return mini;
    }
};