class Solution {
public:
    string multiply(string a, string b) {

        if (a == "0" || b == "0") return "0";

        int n = a.size(), m = b.size();
        vector<int> res(n + m, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int mul = (a[i] - '0') * (b[j] - '0');
                int sum = mul + res[i + j + 1];

                res[i + j + 1] = sum % 10;
                res[i + j] += sum / 10;
            }
        }

        string ans = "";
        int i = 0;
        while (i < res.size() && res[i] == 0) i++;

        for (; i < res.size(); i++) ans.push_back(res[i] + '0');

        return ans;
    }
};
