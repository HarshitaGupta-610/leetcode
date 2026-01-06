class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        for (char digit : num) {
            while (!s.empty() && k > 0 && s.top() > digit) {
                s.pop();
                k--;
            }
            s.push(digit);
        }
        while (k > 0 && !s.empty()) {
            s.pop();
            k--;
        }
        string ans = "";
        while (!s.empty()) {
            ans += s.top();
            s.pop();
        }
     
        reverse(ans.begin(), ans.end());
        while (!ans.empty() && ans[0] == '0') {
    ans.erase(ans.begin());
}
        return ans.empty() ? "0" : ans;
    }
};
