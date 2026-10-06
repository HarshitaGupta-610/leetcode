class Solution {
public:
    int minAddToMakeValid(string s) {
        int mini= 0;
        int valid = 0;
        for (char c : s) {
            if (c == '(')  valid++;
else {
                if (valid == 0) mini++;
         else  valid--;
                
            }
        }

        return mini + valid;
    }
};