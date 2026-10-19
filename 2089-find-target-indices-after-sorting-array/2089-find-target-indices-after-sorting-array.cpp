class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int counting = 0, founting = 0;
        for(auto it : nums){
            if(it < target){
                counting++;
            }else if(it > target){
                founting++;
            }
        }
        vector<int> sol;
        int n = nums.size() - founting - counting;
        for(int i = 0; i < n; i++){
            sol.push_back(i + counting);
        }
        return sol;
    }
};