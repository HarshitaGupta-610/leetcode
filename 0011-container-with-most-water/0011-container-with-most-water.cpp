class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        //brute force: O(n²): har pair ka area check krke maximum find karna
        // int ans = 0;
        // for(int i = 0 ; i < n ; i++){
        //     for(int j = i+1; j < n ; j++){
        //         int area = (j-i)*min(height[i],height[j]);
        //         ans = max(ans,area);
        //     }
        // }
        // return ans;


        //optimal : O(n): using 2 pointers we keep traversing
        /*
     Initially maximum width milegi,
isliye left = 0 aur right = n-1 se start karte hain.
        */
        int l = 0 , r = n-1;
        int maxi = INT_MIN;
        while( l < r){
            //min isliye move kro taki atleast width toh zyada rahe
            int h = min(height[l] , height[r]);
            int base = r -l;
            maxi = max(maxi,h*base);
            if(height[l] < height[r]){
                //badi height ke compatible dhundho
                l++;
            }
            else{
                r--;//chote bar ke compatible
            }
        }
        return maxi;
    }
};