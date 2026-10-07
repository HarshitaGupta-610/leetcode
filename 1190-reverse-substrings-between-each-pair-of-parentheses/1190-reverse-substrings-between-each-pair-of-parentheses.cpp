class Solution {
public:
    string rev(string s) {
        stack<char> sti;
for(char c : s) sti.push(c);
        string ans = "";
        while(!sti.empty()) {
            ans.push_back(sti.top());
            sti.pop();
        }
        return ans;
    }

    string reverseParentheses(string s) {
        while(s.find('(') < s.size()) {
            int close = s.find(')');
            int open = s.rfind('(', close);

            string temp = s.substr(open + 1, close - open - 1);
            temp = rev(temp);

            s.replace(open, close - open + 1, temp);
        }
        return s;
    }
};