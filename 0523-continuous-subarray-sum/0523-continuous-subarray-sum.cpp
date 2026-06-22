class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        m[0] = -1; // intially remainder0 kisi bhi index ka nahi hai
        int currSum = 0;
        for(int i = 0 ; i < nums.size(); i++){
            currSum += nums[i];
            int rem = currSum % k;
            if(m.find(rem) != m.end()){
                if(i - m[rem] >= 2){
                    return true;
                }
            }
            else{
                    m[rem] = i;
                }
                
            


        }
        return false;
    }
};