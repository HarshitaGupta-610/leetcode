class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int ss = s.size(), ts = t.size();
        for (int is = ss - 1, it = ts - 1, skip1{}, skip2{}; is >= 0 || it >= 0; ) {
            while (is >= 0) {
                if (s[is] == '#') {
                    skip1++;
                    is--;
                } else if (skip1 > 0) {
                    skip1--;
                    is--;
                } else break;
            }
            while (it >= 0) {
                if (t[it] == '#') {
                    skip2++;
                    it--;
                } else if (skip2 > 0) {
                    skip2--;
                    it--;
                } else break;
            }
            if(it >= 0 && is >= 0) {
                if(s[is] != t[it]) return false;
            } else if (is >= 0 || it >= 0) return false;
            is--; it--;
        }
        return true;
    }
};