class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        
        int n = nums.size();
        int count = 0;
        
        int totalSum = 0;
        for(int x : nums){
            totalSum += x;
        }
        
        int leftSum = 0;
        
        for(int i = 0; i < n-1; i++){
            
            leftSum += nums[i];
            
            int rightSum = totalSum - leftSum;
            int rightCount = n - i - 1;
            
            if(nums[i] * rightCount > rightSum){
                count++;
            }
        }
        
        return count;
    }
};