class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int id = -1;
        for(int i = n - 2 ; i >= 0 ; i --){
            if(nums[i +1] > nums[i]){
                id = i;
                break;
            }
        }
         if(id  == -1){
            reverse(nums.begin() , nums.end());
            return ;
         }
        for(int i = n-1 ; i >= 0  ; i--){
            if(nums[i] > nums[id]){
                swap(nums[i] , nums[id]);
                break;
            }
        }
        reverse (nums.begin() + id + 1,nums.end());
        return;
     
    }
};