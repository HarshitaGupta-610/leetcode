class Solution {
public:

bool checkOrder(vector<int>&nums){
    for(int i = 0 ; i < nums.size()-1 ; i++){
        if(nums[i] > nums[i+1]){
            return false;
        }
    }
    return true;
}
    int minimumPairRemoval(vector<int>& nums) {
        int ops = 0;
        while(!checkOrder(nums)){
            int index = 0;
            int miniSum = INT_MAX;
            for(int i = 0 ; i < nums.size()-1 ;i++){
                 int sum = nums[i] + nums[i+1];
                 if(sum < miniSum){
                    miniSum = sum;
                    index = i;
                 }
            }
            nums[index] = nums[index] + nums[index +1];
            nums.erase( nums.begin()  + index + 1);
            ops++;
        }
        return ops;
    }
};