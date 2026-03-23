class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefixCount;
    prefixCount[0] = 1;
    int prefix_sum = 0, result = 0;

    for (int num : nums) {
        prefix_sum += num;

        if (prefixCount.find(prefix_sum - k) != prefixCount.end()) {
            result += prefixCount[prefix_sum - k];
        }

        prefixCount[prefix_sum]++;
    }

    return result;
}

};