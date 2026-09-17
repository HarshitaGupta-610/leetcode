class Solution {
public:
   int atMostK(vector<int>& nums, int k) {
 int n = nums.size(); 
  int l = 0 ;
  int ans = 0;//count of valid subarrays
  unordered_map<int,int>m;
  for(int r = 0; r < n; r++) {
         m[nums[r]]++;//us element ki freq badahao
while(m.size() > k) {// k distinct se zyada hogaye
m[nums[l]]--;//left ki freq hatao
if(m[nums[l]] == 0) m.erase(nums[l]);//ab toh poora hi left wala hat gaya
l++;
}
 ans += r - l + 1;
}
    return ans;  
    }


    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // Exactly K = At most K - At most (K-1)
    return (atMostK(nums, k) -atMostK(nums, k - 1));
    }
};