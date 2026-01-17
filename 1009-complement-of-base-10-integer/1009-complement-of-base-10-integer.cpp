class Solution {
public:

 
    string toBinary(int n) {
        if (n == 0){
             return "0";
        }
        string ans = "";
        while (n > 0) {
            ans = char('0' + (n % 2)) + ans;
            n /= 2;
        }
        return ans;
    }

    int binaryToInt(const string &bin) {
        bool neg = false;
        int i = 0;

        if (bin[0] == '-') {
            neg = true;
            i = 1;
        }

        int val = 0;
        for (; i < bin.size(); i++) {
            val = val * 2 + (bin[i] - '0');
        }

        return neg ? -val : val;
    }

    int bitwiseComplement(int n) {
        string b = toBinary(n);

        for (char &c : b) {
            c = (c == '0') ? '1' : '0';
        }

        return binaryToInt(b);
    }
};
