class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
    //   //Brute force : O(NXN) , use loops to traverse and find if any pair exists
    //   for(int i = 0 ; i < n ; i++){
    //     for(int j = i+1 ; j < n ; j++){
    //         if(nums[i] + nums[j] == target){
    //             return {i,j};
    //         }
    //     }
    //   }
    //   return {};
    // }

    // //Better Approach : map mein complement find karlo : O(n)
    // unordered_map<int,int>m;
    // for(int i = 0 ; i < n; i++){
    //     if(m.find(target-nums[i]) != m.end()){
    //         return {m[target-nums[i]] , i};
    //     }
    //     else{
    //         m[nums[i]] = i;
    //     }
       
    // }
    //  return {};


//optimal O(nlogn) via bianry search
vector<pair<int,int>> arr;

        for(int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end());

        int l = 0;
        int r = n - 1;

        while(l < r) {

            int sum = arr[l].first + arr[r].first;

            if(sum == target) {
                return {arr[l].second, arr[r].second};
            }

            else if(sum < target) {
                l++;
            }

            else {
                r--;
            }
        }

        return {};
    }


};