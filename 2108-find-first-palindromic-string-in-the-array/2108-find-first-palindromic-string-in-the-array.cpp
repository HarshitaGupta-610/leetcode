class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto i:words){
            string s=i;
            reverse(i.begin(), i.end());
            if(i==s){
                return s;
            }
        }
        return "";
    }
};