class Solution {
public:
    int lastRemaining(int n) {
        int start = 1;     
        int gap = 1;      
        bool fromLeft = true;  

        while (n > 1) {
            if ( fromLeft || n % 2 == 1) {
                start += gap; 
            }
            gap *= 2;   
            n /= 2;    
           fromLeft  = !fromLeft ;
        }

        return start;
    }
};
