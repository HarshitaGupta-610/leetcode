class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        string x = "";
        long long sum = 0;

        for (char c : s) {
            int d = c - '0';
            if (d != 0) {
                x += c;      
                sum += d;   
            }
        }

        long long num = 0;
        if (!x.empty()) {
            num = stoll(x);  
        }

        return num * sum;
    }
};
