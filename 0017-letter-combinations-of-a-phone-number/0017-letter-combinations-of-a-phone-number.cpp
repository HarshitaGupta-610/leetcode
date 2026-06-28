class Solution {
public:
    vector<string> ans;

    void solve(string digits, int index, string op)
    {
        vector<string> keypad = {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz",
        };

        if(index == digits.size())
        {
            ans.push_back(op);
            return;
        }

        string letters = keypad[digits[index] - '0'];

        for(int i = 0; i < letters.size(); i++)
        {
            string op1 = op;
            op1.push_back(letters[i]);

            solve(digits, index + 1, op1);
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if(digits.size() == 0)
        {
            return {};
        }

        solve(digits, 0, "");

        return ans;
    }
};