class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0 , r = 0;
        int countofZeroes = 0;
        int maxi = 0;
        for(int r = 0 ; r < nums.size() ; r++ ){
            if(nums[r] == 0){
                countofZeroes ++;
            }
            if(countofZeroes > k ){
                
                if(nums[l] == 0){
                countofZeroes--;
                }
                l++;
            }
            maxi = max(maxi , r - l +1);
        }
        return maxi;
    }
};