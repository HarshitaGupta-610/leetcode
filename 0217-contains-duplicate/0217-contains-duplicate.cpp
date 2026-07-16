class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();



        // //Brute force :  O(n²) Because for each element, we are checking every future element nested loops.
        // for(int i = 0 ; i < n ; i++){
        //     for(int j = i + 1 ; j < n ; j++){
        //         if(nums[i] == nums[j]){
        //             return true;
        //         }
        //     }
        // }
        // return false;



        // //Better approach :O(nlogn) sort and keep coparing with previous
        // sort(nums.begin() , nums.end());
        // for(int i = 1 ; i < n ; i++){
        //     if(nums[i] == nums[i-1]){
        //         return true;
        //     }
        // }
        // return false;



        //optimal : O(n) unordered_Set mein daldo if set and vector ka size same toh no duplicate
      unordered_set<int>s(nums.begin() , nums.end());
        if(s.size() == nums.size()){
            return false;
        }
        return true;
    }
};