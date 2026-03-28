class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

if(n==1){
    return nums[0];
}
        // agar 0 se n-2 tak jaana hai
        int prev2 = 0;
        int prev1 = nums[0];

        for(int i = 1; i <= n-2; i++){
            int pick = nums[i] + prev2;
            int notPick = prev1;

            int curr = max(pick, notPick);

            prev2 = prev1;
            prev1 = curr;
        }

        int case1 = prev1;

        // jab 1 se n-1
        prev2 = 0;
        prev1 = nums[1];

        for(int i = 2; i <= n-1; i++){
            int pick = nums[i] + prev2;
            int notPick = prev1;

            int curr = max(pick, notPick);

            prev2 = prev1;
            prev1 = curr;
        }

        int case2 = prev1;
         return max(case1, case2);
    }
};