class Solution {
public:
    int minBitFlips(int start, int goal) {
    //we ned to change different bits
    //to check diff bits weneed xor
    int x = start ^ goal;//donon ka zor , usme jo 1 hogi bits yani we need to change m uska count is answer
    int ans = 0;    
    while(x){
       ans += (x & 1);
        x = x >> 1;
    }
    return ans;
    }
};