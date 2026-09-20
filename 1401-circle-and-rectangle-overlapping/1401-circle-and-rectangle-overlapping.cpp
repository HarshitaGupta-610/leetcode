class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int x_point = max(x1,min(xCenter , x2));//overlap ke liye x coordinate
        int y_point = max(y1,min(yCenter , y2));//overlap ke liye y coordinate

        return (radius*radius) >=( pow(x_point-xCenter,2) + pow(y_point - yCenter ,2));
    }
};