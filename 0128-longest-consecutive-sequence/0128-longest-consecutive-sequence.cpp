class Solution {
public:
    int longestConsecutive(vector<int>& nums) {


  //Brute Force : O(n²)
//   int ans =0;
//   for(int num : nums){
//     int current = num;
//     int count =1;
//     while(find(nums.begin() , nums.end() , current +1) != nums.end()){
//         current++;
//         count++;
//     }
//     ans = max(ans,count);
//   }
//   return ans;


//Better : O(nlogn)
// sort(nums.begin() , nums.end());
// if(nums.empty()) return {};
// int ans =1;
// int curr = 1;
// for(int i = 1 ; i < nums.size() ; i++){
//     if(nums[i] == nums[i-1]) continue;
//     if(nums[i] == nums[i-1] +1)curr++;
//     else curr = 1;
//     ans = max(ans,curr);
// }
// return ans;


//Optimal : O(N) use of set
unordered_set<int>s(nums.begin() , nums.end());
int longest = 0;
for(int num : s){
if(s.find(num-1) != s.end()) continue;
int curr = num;
int count =1;
while(s.find(curr +1) != s.end()){
    curr++;
    count++;
}
longest = max(longest , count);
}
return longest;
    }
};