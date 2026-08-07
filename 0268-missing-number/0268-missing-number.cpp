class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        //Brute force: O(n²)
        // for(int i = 0 ; i <= n ; i++){
        //     bool found = false;  
        //     for(int j = 0 ; j < n ; j++){
        //    if(nums[j] == i){
        //     found = true;
        //     break;
        //    }
        //     }
        //     if(found == false) return i;
        // }

//Brute force : O(N)
//map mein daalo and see if frequency is 0 then it is the answer
// unordered_map<int,int>m;
// for(int num : nums){
//     m[num]++;
// }
// for(int i = 0 ; i <= n ; i++ ){
//     if(m[i] != 1){
//         return i;
//     }
// }

//Optimal: O(n)
//take sum of total and what sum should be and subtract to get answer
// int sum = 0;
// for(int num : nums){
//     sum += num;
// }
// int total = (n * (n+1) )/ 2;
// return total - sum;


//XOR METHOD : O(N)
//xor of all start from xor is 0 as  0 xor o would be 0 , and all number xor any number would be number 
int ans = 0;
        // 0 se n tak sab numbers ka XOR
        for (int i = 0; i <= n; i++) {
            ans ^= i;
        }
        // Array ke sab elements ka XOR
        for (int num : nums) {
            ans ^= num;
        }
        // Sirf missing number bachega
        return ans;

        
return -1;
    }
};