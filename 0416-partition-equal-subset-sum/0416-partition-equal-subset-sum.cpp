class Solution {
public:
    bool canPartition(vector<int>& nums) {int total = 0;

        for(int num : nums){
            total += num;
        }
        if(total % 2 != 0){
            return false;
        }
        int target = total / 2;

        int n = nums.size();

        // DP Table
        //
        // Rows (i)    -> First i elements consider kiye hain.
        // Columns (j) -> Kya sum j bana sakta hai?
        //
        // dp[i][j] =
        // true  -> Agar first i elements use karke sum j ban sakta hai.
        // false -> Agar nahi ban sakta.
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));



        
        // Sum = 0 hamesha possible hai as empty subset lelo
        for(int i = 0; i <= n; i++){
            dp[i][0] = true;
        }

       

        // ---------------- DP TABLE FILL ----------------

        // i = kitne elements consider kar rahe hain
        for(int i = 1; i <= n; i++){

            // j = current target sum
            for(int j = 1; j <= target; j++){

                // Current element
                int curr = nums[i - 1];

                // Agar current element current sum se chhota ya equal hai,
                // to humare paas 2 choices hain.

                if(curr <= j){

                    // ---------------- Choice 1 ----------------
                    //
                    // Current element ko le lo.
                    //
                    // Agar current element lete hain,
                    // to remaining sum banani padegi.
                    //
                    // Example:
                    //
                    // current sum = 11
                    // current element = 8
                    //
                    // Remaining sum = 11-8 = 3
                    //
                    // Check:
                    // Kya previous elements se sum 3 ban sakta hai?

                    bool take = dp[i - 1][j - curr];



                    // ---------------- Choice 2 ----------------
                    //
                    // Current element ko mat lo.
                    //
                    // Fir wahi sum previous elements se banana padega.

                    bool notTake = dp[i - 1][j];



                    // Agar dono me se koi bhi true hai,
                    // to answer true hoga.

                    dp[i][j] = take || notTake;
                }

                else{

                    // Agar current element current sum se bada hai,
                    //
                    // Example:
                    //
                    // current element = 10
                    // current sum = 6
                    //
                    // To 10 ko le hi nahi sakte.
                    //
                    // Sirf ek hi option bachta hai:
                    // Don't Take.

                    dp[i][j] = dp[i - 1][j];
                }
            }
        }



        // Last cell batayega ki
        // kya first n elements use karke target sum bana sakte hain.
        return dp[n][target];
    }
};