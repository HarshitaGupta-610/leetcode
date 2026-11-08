class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        vector<int> pos, neg;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0)
                pos.push_back(nums[i]);
            else
                neg.push_back(nums[i]);
        }

        vector<int> ans(nums.size());

        for(int i = 0; i < pos.size(); i++) {
            ans[2 * i] = pos[i];
            ans[2 * i + 1] = neg[i];
        }

        return ans;
    }
};