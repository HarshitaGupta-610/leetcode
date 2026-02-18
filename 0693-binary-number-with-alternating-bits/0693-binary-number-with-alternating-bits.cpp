class Solution {
public:
    bool hasAlternatingBits(int n) {
        while( n != 0){
            int temp1 = n & 1;
            n >>= 1;
            int temp2 = n & 1;
            if(temp1 == temp2){
                return false;
            }
        }
        return true;
    }
};