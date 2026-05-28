class Solution {
public:
    int passwordStrength(string password) {
        unordered_map<char, int> mp;
        for(char ch : password) {
            mp[ch]++;
        }
int ans = 0;
        for(auto it : mp) {

            char c = it.first;

            if(c >= 'a' && c <= 'z') {
                ans += 1;
            }
            else if(c >= 'A' && c <= 'Z') {
                ans += 2;
            }
            else if(c >= '0' && c <= '9') {
                ans += 3;
            }
            else {
                ans += 5;
            }
        }

        return ans;
    }
};