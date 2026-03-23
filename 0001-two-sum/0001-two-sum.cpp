class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mapo;

        for(int i = 0 ; i < nums.size();i++){
            int complement = target - nums[i];

            if(mapo.find(complement) != mapo.end()){
                return {mapo[complement] , i};
            }

            mapo[nums[i]]=i;
        }
        return {};
    }
};