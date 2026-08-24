class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();



// //Brute : O(n²)For every bar, find the tallest bar on its left and right, take the shorter one as the water level, subtract the current bar’s height, and add that trapped water to the total.
// int water = 0;
// for(int i = 0 ; i < n ; i++){
//     int left = 0;
//     for(int j = 0 ; j < i ; j++){
// left = max(left , height[j]);
//     }
//     int right = 0;
//     for(int j = i+1 ; j < n ; j++){
//         right = max(right , height[j]);
//     }
//     int waterAtI = min(left, right) - height[i];
// if(waterAtI > 0)
//     water += waterAtI;
// }
// return water;

/*Optimal : O(N)
Dono ends se pointers chalao, jis side ki current height chhoti hai us side ko process karo, aur us side ke maximum wall se current height ka difference water mein add karo.*/
// Left pointer array ke starting se
        int left = 0;
        // Right pointer array ke ending se
        int right = n - 1;
   // Left side ka ab tak ka sabse bada bar
        int leftMax = 0;
        // Right side ka ab tak ka sabse bada bar
        int rightMax = 0;
        // Total trapped water
        int water = 0;
        // Jab tak left aur right pointers cross nahi karte
        while(left <= right) {
            // Agar LEFT wala bar chhota hai
            // toh LEFT side ko process karenge
            if(height[left] <= height[right]) {
                // Agar current left bar,
                // ab tak ke leftMax se bhi bada hai
                // toh ye naya tallest left wall hai
                if(height[left] >= leftMax) {

                    leftMax = height[left];
                }

                // Current bar leftMax se chhota hai
                // matlab iske upar water trap hoga
                else {

                    // Water = leftMax - current height
                    water += leftMax - height[left];
                }

                // Left pointer ko ek step aage badhao
                left++;
            }


            // Agar RIGHT wala bar chhota hai
            // toh RIGHT side ko process karenge
            else {

                // Agar current right bar,
                // ab tak ke rightMax se bada hai
                // toh ye naya tallest right wall hai
                if(height[right] >= rightMax) {

                    rightMax = height[right];
                }

                // Current bar rightMax se chhota hai
                // matlab iske upar water trap hoga
                else {

                    // Water = rightMax - current height
                    water += rightMax - height[right];
                }

                // Right pointer ko ek step peeche le jao
                right--;
            }
        }

        // Total trapped water return karo
        return water;
    }
};