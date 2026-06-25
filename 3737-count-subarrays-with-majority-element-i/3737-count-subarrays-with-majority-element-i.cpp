class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int count = 0,j,i;
        for( i = 0 ; i < n;i++){
            int laddoo = 0;
            for( j = i ; j < n ; j++){
                if(nums[j] == target){
                    laddoo++;
                }
                int len = j - i + 1;
            int majority =len / 2;
            if(laddoo > majority){
                count++;
            }
            }
            
        }
        return count;
    }
};