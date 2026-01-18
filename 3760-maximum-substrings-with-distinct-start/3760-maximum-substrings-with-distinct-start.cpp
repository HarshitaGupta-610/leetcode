class Solution {
public:
    int maxDistinct(string s) {
        int n = s.size();
        unordered_set<int>sti;
        for(int i = 0 ; i < n ;i++){
            sti.insert(s[i]);
        }
        return sti.size();
    }
};