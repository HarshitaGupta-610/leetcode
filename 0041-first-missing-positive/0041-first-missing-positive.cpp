class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Har number ko uski correct position par leke jaana hai humein
        // 1 -> index 0
        // 2 -> index 1
        // 3 -> index 2
        // x number -> index x-1
 for(int i = 0; i < n; i++) {
 while(nums[i] >= 1 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
//sahi jagh phonchao
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        // Check karo kaunsa number apni correct position par nahi hai
 for(int i = 0; i < n; i++) {
    if(nums[i] != i + 1) {
                return i + 1;
            }
        }
// Agar 1 se n tak sab present hain
        return n + 1;
    }
};
