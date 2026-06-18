class Solution {
public:
vector<string>a;
void solve(int open, int close, string op)
{
    
    if(open == 0 && close == 0)
    {
    
        a.push_back(op);
        return;
    }

    if(open > 0)
    {
        string op1 = op;
        op1.push_back('(');
         solve(open-1, close, op1);
    }

    if(close > open)
    {
        string op2 = op;
        op2.push_back(')');
        solve(open, close-1, op2);
    }
}
    vector<string> generateParenthesis(int n) {
        solve(n ,n , "");
        return a;
    }
};