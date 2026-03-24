class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int minprice = prices[0];

        for(int price : prices){
            minprice = min(price,minprice);
            ans = max (ans,price - minprice);
        }
        return ans;
    }
};