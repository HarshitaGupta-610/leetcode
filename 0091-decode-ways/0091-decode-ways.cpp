class Solution {
public:
  
     //Brute force:O(2ⁿ) // har string ko 2 ways ke thorugh dekho   
// int solve(int i , string&s){
        // solve(i) = String ke index i se lekar end tak
    // total kitne valid decoding ways possible hain.
        // if(i == s.size()) return 1;//ab toh koi characater hai hi nahi
        // if(s[i] == '0') return 0;
        //Choice 1
        // int digitOnlyOne = solve(i+1,s);//Current digit ko single character ki tarah decode karo.
        // int digit2 = 0;// 2digits hum naan hi nahi rahe
        //Choice 2
    //     if(i+1<s.size()){
    //     int num = (s[i]-'0')*10 + (s[i+1] -'0');//current aur next
    //     if(num >= 10 && num <= 26) digit2 = solve(i+2,s);
    //     }
    //     return digitOnlyOne + digit2;
    //     }
    //   int numDecodings(string s) {
    //    return solve(0,s);//pehle index s start krege
    // }
//Optimal : O(n)
 int numDecodings(string s) {
int n = s.size();
vector<int>dp(n+1,0);
dp[n] = 1;
for(int i = n-1 ; i >= 0 ; i--){
    if(s[i] == '0'){
        dp[i] = 0;
        continue;
    }
dp[i] = dp[i+1];
if(i+1 < n){
    int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
    if (num >= 10 && num <= 26) dp[i] += dp[i + 2];
}
}
return dp[0];
}

};