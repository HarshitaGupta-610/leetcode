class Solution {
public:
    bool sumGame(string num) {
int n = num.size();
double left = 0;
double right = 0;
for(int i = 0; i < n / 2; i++) {
if(num[i] == '?')left += 4.5;
else left += num[i] - '0';
}
 for(int i = n / 2; i < n; i++) {
 if(num[i] == '?') right += 4.5;
else right += num[i] - '0';
}
return left != right;
    }
};