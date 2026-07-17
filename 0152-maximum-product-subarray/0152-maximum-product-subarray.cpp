class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();


        //brute force : (O(n²)): har subarray ka prod check karo
        int maxi = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            int p = 1;
            for(int j = i ; j < n ; j++){
                p *= nums[j];  
                 maxi = max(maxi , p);
            }
           
        }
        return maxi;

    }
};