class Solution {
public:
    
    // Yeh recursive function hai jo subsets generate karega
    void solve(int index, vector<int>& nums, 
               vector<int>& current,  // yeh temporary subset hai jo abhi bana rahe hain
               vector<vector<int>>& result) { // yeh final answer hai jisme saare subsets store honge
        
        //Base Case:
        // Agar index nums ke size ke equal ho gaya,
        // matlab humne saare elements consider kar liye
        if (index == nums.size()) {
            
            // Jo current subset bana hai, use result me daal do
            result.push_back(current);
            
            // Ab yeh branch ka kaam khatam, wapas jao (return)
            return;
        }
        
        // 🔹 Choice 1: Include current element
        
        // nums[index] ko current subset me daalo
        current.push_back(nums[index]);
        
        // Next index ke liye recursion call karo
        solve(index + 1, nums, current, result);
        
        // Backtracking step:
        // Ab hum wapas aaye recursion se,
        // toh jo element add kiya tha usko hata do
        // taaki next choice me fresh state mile
        current.pop_back();
        
        // Choice 2: Exclude current element
        
        // Is baar nums[index] ko include nahi kar rahe
        // seedha next index pe chale jao
        solve(index + 1, nums, current, result);
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        // Yeh final answer store karega
        vector<vector<int>> result;
        
        // Yeh ek temporary subset hai (start me empty)
        vector<int> current;
        
        // Recursion start karo index 0 se
        solve(0, nums, current, result);
        
        // Saare subsets return karo
        return result;
    }
};