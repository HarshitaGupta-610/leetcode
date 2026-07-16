class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int maxi = 0;
       int n = prices.size();
    //    //brute force  :O(n²) Because for each element, we are checking every future element nested loops.
    //    for(int i = 0 ; i < n ; i++){
    //     for(int j = i +1 ; j < n ; j++){
    //         maxi = max(maxi , prices[j] - prices[i]);
    //     }
    //    }
    //    return maxi;


    //traverse krte krte hi profit calcualte krte jao max profit tabhi hoga jab min mein kahreeda ho O(n)
    int kamPrice = INT_MAX;
    for(int i = 0 ; i < n ; i++){
if(prices[i] < kamPrice){
    kamPrice = prices[i];
}
maxi = max(maxi , prices[i] - kamPrice);
    }
    return maxi;
    }
};