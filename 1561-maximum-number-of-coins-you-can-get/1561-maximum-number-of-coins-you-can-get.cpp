class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin() , piles.end());
        int n = piles.size();
        int batches = n / 3;
        int youhave = 0;
        int youstart = n-2;//second last max aapka pehla hai
        while(batches--){
            youhave += piles[youstart];
            youstart-=2;

        }

return youhave;
    }
};