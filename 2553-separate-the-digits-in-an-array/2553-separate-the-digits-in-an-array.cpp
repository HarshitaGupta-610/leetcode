class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        for(int num : nums){
            string s = to_string(num);
            for(int i = 0 ; i < s.size(); i++){
                ans.push_back(s[i] - '0');
            }
        }
        return ans;
    }
};