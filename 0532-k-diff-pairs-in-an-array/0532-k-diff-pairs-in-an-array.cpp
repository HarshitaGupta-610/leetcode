class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
         int n = nums.size();
        
        //Brute Force : O(n² log n)
        // set<pair<int,int>>st;
        // for(int i = 0 ; i < n ; i++){
        //     for(int j = i +1 ; j < n ; j++){
        //         if(abs(nums[j] - nums[i])  ==  k){
        //             st.insert({
        //                 min(nums[i] , nums[j]),
        //                 max(nums[i] , nums[j])
        //             });
        //         }
        //     }
        // }
        // return st.size();

//Better:Sort the array and use two pointers to find pairs with difference k → O(n log n)
    sort(nums.begin() , nums.end());
        int i = 0 , j = 1, ans = 0;
        while(j < n){
            if(i == j) {
                j++;
                  continue;
        }
            int diff = nums[j] - nums[i];
            if(diff == k){
                ans++;
            int left = nums[i];
            int right = nums[j];
            while( i < n && nums[i] == left)i++;
            while( j < n && nums[j] == right)j++;
            }else if(diff<k){
                j++;
            }else{
                i++;
            }
        }
        return ans;
    }
};