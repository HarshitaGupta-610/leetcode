class Solution {
public:
    int minElement(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            int sum = 0;
            while(nums[i] != 0){
                int digit = nums[i] % 10;
                sum += digit;
                nums[i] /= 10;
            }
            nums[i] = sum;
        }
        sort(nums.begin() , nums.end());
        return nums[0];
    }
};