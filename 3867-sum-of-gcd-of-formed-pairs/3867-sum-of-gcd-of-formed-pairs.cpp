class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefixGcd; //prefixGcd array jisme gcds stre karege hum
        int mx = INT_MIN ; // maximum value till given i jo bhi chahhiye hogi
        for(int i = 0 ; i < n ; i++){
            mx = max(mx , nums[i]);
            prefixGcd.push_back(gcd(mx , nums[i]));
        }
        sort(prefixGcd.begin() , prefixGcd.end());

        int i = 0;
        int j = n - 1;
        long long ans = 0;
        while(i < j){
ans += gcd(prefixGcd[i]  , prefixGcd[j]);
i++;
j--;
        }
        return ans;
    }
};