class Solution {
public:
    int characterReplacement(string s, int k) {
     int l = 0;//to traverse or iterate
     int maxi = 0;//final ans
     int ans = 0;
     unordered_map<int,int>mp;
     for(int r = 0 ; r < s.size() ; r++){
        mp[s[r]]++;
        maxi = max(maxi,mp[s[r]]);
        if((r-l+1) - maxi > k){//replacements needed = window length − frequency of most frequent character.
            mp[s[l]]--;
            l++;
        }
        ans = max(ans,r-l+1);
     }
return ans;
    }
};