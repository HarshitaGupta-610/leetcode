class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        // Har row ke reserved seats ko store karenge map mein
        // row -> us row ki reserved seats
        unordered_map<int, set<int>> mp;
        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1]; 
            // Is row mein ye seat reserved hai
            mp[row].insert(col);
        }
        //agar poori row khali hai toh hum maximum 2 maanke chalege
        int ans = 2 * (n - mp.size());
        // Sirf unhi rows ko check karna hai
        // jahan koi reservation hai
        for (auto &[row, seats] : mp) {
            
            bool left = true;
            bool middle = true;
            bool right = true;
            for (int i = 2; i <= 5; i++) {
                
                if (seats.count(i)) {
                    left = false;
                    break;
                }
            }

            for (int i = 6; i <= 9; i++) {
                
                if (seats.count(i)) {
                    right = false;
                    break;
                }
            }
            
            
           //middle seat
            for (int i = 4; i <= 7; i++) {
                
                if (seats.count(i)) {
            
                    middle = false;
                    break;
                }
            }
            
          
            if (left && right) {
                
                // LEFT aur RIGHT dono available hain
                ans += 2;
            }
            
            else if (left || middle || right) {
                
                // toh 1 group add kar do.
                ans += 1;
            }
            
            
        }
        
        return ans;
    }
};