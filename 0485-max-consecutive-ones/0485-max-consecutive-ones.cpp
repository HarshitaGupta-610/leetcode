class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int curr = 0;
        for(int num : nums){
            if( num == 1){
                curr++;
            }
            else{
                curr = 0;
            }
            maxi = max(maxi,curr);
        }
        return maxi;
    }
};