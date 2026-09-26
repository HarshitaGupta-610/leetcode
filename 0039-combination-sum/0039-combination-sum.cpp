class Solution {
public:
    void targetSum(vector<int>& candidates, int index, int& currSum,
                   int& target, vector<int>& temp, vector<vector<int>>& ans) {

        // Base Case
        if (index == candidates.size()) {
            if (currSum == target)
                ans.push_back(temp);

            return;
        }

        // Pruning
        if (currSum >= target) {
            if (currSum == target)
                ans.push_back(temp);

            return;
        }

        // include current element into sum
        temp.push_back(candidates[index]);
        currSum += candidates[index];
        targetSum(candidates, index, currSum, target, temp, ans);
        temp.pop_back();
        currSum -= candidates[index];

        // don't include current element into sum
        targetSum(candidates, index + 1, currSum, target, temp, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        int sum = 0;
        targetSum(candidates, 0, sum, target, temp, ans);

        return ans;
    }
};