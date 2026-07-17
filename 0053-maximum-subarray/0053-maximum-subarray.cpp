class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

    //     // brute force : O(n²)    
    //     /*find sum of every possible subarray 
    //     and keep updating maximum
    //     */
    //     int maxi = INT_MIN;
    //     for(int i = 0 ; i < n ; i++){
    //     int sum = 0;
    //       for(int j = i ; j < n ; j++){
    //             sum += nums[j];
    //             maxi = max(maxi , sum);
    //         }
    //     }
    //     return maxi;
    // }

    //optimal approach : kadane's algo O(n)
    /* 
    jaise hi sum negative ho , sum ko reinitialise 0 se krdo aur simultanesouly maximum sum save krte rho
    */
    int sum = 0;
    int maxi = INT_MIN;
    int i = 0;
    while( i < n ){
        sum += nums[i];
        maxi = max(sum , maxi);
        if(sum < 0){
            sum = 0;
        }
        i++;
    }
    return maxi;
    }

};