class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0  , r = 0;
        vector<int>f(256,0);
        
        int n = s.size();
        int maxi = 0;
        for(int r = 0 ; r < n ; r++ ){
            f[s[r]]++;
            while(f[s[r]] > 1){
                f[s[l]]--;
                l++;
            }
            maxi = max(maxi , r - l +1);
        }
        return maxi;
    }
};