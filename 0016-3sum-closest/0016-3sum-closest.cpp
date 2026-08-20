class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();

//Brute 3 loops → O(n³)
        // int closest = nums[0] + nums[1] + nums[2];
        // for(int i = 0 ; i < n ; i++){
        //     for(int j = i+1 ; j < n ; j++){
        //         for(int k = j +1 ; k < n ; k++){
        //             int sum = nums[i] + nums[j] + nums[k];
        //             if(abs(sum-target) < abs(closest - target)){
        //                 closest = sum;
        //             }
        //         }
        //     }
        // }
        // return closest;


//Array sort karo, ek i fix karo, phir l aur r se remaining 2 elements search karo; sum chhota ho toh l++, bada ho toh r--, aur har step par target ke closest sum ko closest mein store karo.O(n²)
sort(nums.begin(), nums.end());
 int closest = nums[0] + nums[1] + nums[2];
 for(int i = 0; i < n - 2; i++) {
        int l = i + 1;
            int r = n - 1;
            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                // Current sum target ke closer hai
                if(abs(sum - target) < abs(closest - target)) {
                    closest = sum;
                }
                // Exact target mil gaya
                if(sum == target) {
                    return target;
                }
                // Sum chhota hai → sum badhana hai
                if(sum < target) {
                    l++;
                }
                   // Sum bada hai → sum ghataana hai
                else {
                    r--;
                }
            }
        }

        return closest;
    }
};