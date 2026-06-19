class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int f5s = 0 ,t10s = 0 ;
        for(int bill : bills){
            if(bill == 5){
                f5s++;
            }
            else if(bill == 10){
                t10s++;
                if(f5s > 0){
                    f5s--;
                }
                else{
                    return false;
                }
            }
            else{
                if(f5s > 0 && t10s > 0){
                    f5s--;
                    t10s--;
                }
                else if(f5s >= 3){
            f5s-=3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};