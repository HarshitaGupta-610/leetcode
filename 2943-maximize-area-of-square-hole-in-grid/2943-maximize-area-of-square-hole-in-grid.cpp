class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int cons = 1, maxi = 1, vcons = 1, vmaxi = 1;
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        for(int i = 1; i < hBars.size(); i++)
        {
            if(hBars[i] - hBars[i-1] == 1){
                cons += 1;
                maxi = max(cons, maxi);
            }
            else
                cons = 1;
        }
        for(int i = 1; i < vBars.size(); i++)
        {
            if(vBars[i] - vBars[i-1] == 1){
                vcons += 1;
                vmaxi = max(vmaxi, vcons);
            }
            else
                vcons = 1;
            
        }
        return pow(min(vmaxi, maxi) + 1, 2);
    }
};