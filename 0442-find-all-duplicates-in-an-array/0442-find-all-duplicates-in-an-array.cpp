class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
    int n = nums.size();
    if(n == 0) return {};
    //Har number x ke liye index x-1 par jaake us element ko negative mark kar dete hain. Agar woh already negative hai, matlab x pehle aa chuka hai, so woh duplicate hai; abs() isliye use kiya kyunki elements negative ho sakte hain.
    vector<int>ans;
    for(int i = 0 ; i < n ; i++){
   if(nums[abs(nums[i])-1]<0){
    ans.push_back(abs(nums[i]));
   }
            nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];     
    }   
    return ans; 
    }
};