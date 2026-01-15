class Solution {
public:
    int maxConsecutive(vector<int>& bars) {
        sort(bars.begin(), bars.end());

        int maxLen = 1, currLen = 1;

        for (int i = 1; i < bars.size(); i++) {
            if (bars[i] == bars[i-1] + 1) {
                currLen++;
            } else {
                maxLen = max(maxLen, currLen);
                currLen = 1;
            }
        }
        maxLen = max(maxLen, currLen);
        return maxLen;
    }

    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int maxH = maxConsecutive(hBars);
        int maxV = maxConsecutive(vBars); 

        int side = min(maxH + 1, maxV + 1); 

        return 1LL * side * side; 
    }
};