class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {

        int x1 = rec1[0];
        int y1 = rec1[1];
        int x2 = rec1[2];
        int y2 = rec1[3];

        int X1 = rec2[0];
        int Y1 = rec2[1];
        int X2 = rec2[2];
        int Y2 = rec2[3];

        if (x1 < X2 && x2 > X1 && y1 < Y2 && y2 > Y1) {
            return true;
        }

        return false;
    }
};