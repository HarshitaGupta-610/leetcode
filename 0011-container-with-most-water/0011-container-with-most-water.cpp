class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int maxi = 0;
       while( l < r){
        int w = r - l;
        int len = min(height[l] , height[r]);
        maxi = max(maxi , w * len);
        if( height[l] < height[r]){
l++;
        }
        else{
r--;
        }
       }
       return maxi;
    }
};
