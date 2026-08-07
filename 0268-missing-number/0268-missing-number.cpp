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
unordered_map<int,int>m;
for(int num : nums){
    m[num]++;
}
for(int i = 0 ; i <= n ; i++ ){
    if(m[i] != 1){
        return i;
    }
}

        
return -1;
    }
};