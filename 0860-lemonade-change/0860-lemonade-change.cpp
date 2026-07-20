class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();

        //Brute:
        int count5 = 0;
        int count10 = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if(bills[i] == 5){
                count5++;
            }
            else if( bills[i] == 10){
                if(count5 != 0){
                    count5--;
                    count10++;
                }else{
                    return false;
                }
            }
            else {

                if(count5>=1 && count10 >=1){
                    count10--;
                    count5--;
                }
                else if(count5 >= 3) {
                    count5-=3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};