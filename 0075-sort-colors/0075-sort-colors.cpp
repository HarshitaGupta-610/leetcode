class Solution {
public:
    void sortColors(vector<int>& nums) {


//Brute : O(nlogn)
// sort(nums.begin() , nums.end());
//     }


//Better : O(N) count and put
// int count0 = 0;
//         int count1 = 0;
//         int count2 = 0;
//          for (int num : nums) {
//             if (num == 0)count0++;
//             else if (num == 1)count1++;
//             else count2++;
//         }
//          int i = 0;
//         while (count0--) {
//             nums[i++] = 0;
//         }
//         while (count1--) {
//             nums[i++] = 1;
//         }
//         while (count2--) {
//             nums[i++] = 2;
//         }


//Optimal : O(N) Dutch National Flag
//Use three pointers (low, mid, high) to keep 0s on the left, 1s in the middle, and 2s on the right in a single pass.
 int low = 0;
        int mid = 0;
        int high = nums.size() - 1;
while (mid <= high) {
            if (nums[mid] == 0) {//peeche bhejo
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1) {//mid mein 1 hi hona chahiye
                mid++;
            }
            else {//2 hai aage bhejo ise
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};