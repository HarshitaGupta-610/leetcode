class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int count5s = 0 , count10s = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(bills[i] == 5){
               count5s++;
            }
            else if( bills[i] == 10){
                if(count5s == 0){
                    return false;
                }
                else{
                count10s++;
                count5s--;
                }
            }
            else{
                if(count10s > 0 && count5s > 0){
                    count5s --;
                    count10s--;

                }
                else if(count5s >= 3){
                    count5s -= 3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};