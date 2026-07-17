class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();


    //     //brute force : (O(n²)): har subarray ka prod check karo
    //     int maxi = INT_MIN;
    //     for(int i = 0 ; i < n ; i++){
    //         int p = 1;
    //         for(int j = i ; j < n ; j++){
    //             p *= nums[j];  
    //              maxi = max(maxi , p);
    //         }         
    //     }
    //     return maxi;
    // }


    //optimal approach : O(n): we will keep amxi and mini products 
    int maxi = nums[0];//abhi ke index tak kya maximum hai
    int mini = nums[0];//abhbi tak ke index tak kya minimum hai
    int final = nums[0];//atlast final answer kya hai
    for(int i = 1 ; i < n ; i++){
        if(nums[i] < 0){
            swap(mini , maxi);
        }
         // Agar current element negative hai,
    // to sign reverse ho jayega.
    //
    // Example:
    // maxi = 6, mini = -12
    // current = -2
    //
    // 6 * -2   = -12   (maximum -> minimum)
    // -12 * -2 = 24    (minimum -> maximum)
    //
    // Matlab jo pehle maximum tha wo minimum ban sakta hai,
    // aur jo pehle minimum tha wo maximum ban sakta hai.
    // Isliye pehle swap kar dete hain.
            maxi = max(nums[i] , maxi * nums[i]);/*// Ab maximum product calculate karte hain.
    //
    // Do choices hain:
    //
    // Choice 1:
    // Current element se hi nayi subarray start karo.
    // Product = nums[i]
    //
    // Choice 2:
    // Previous maximum product wali subarray ko continue karo.
    // Product = maxi * nums[i]
    //
    // Example:
    // nums = [2,3,4]
    //
    // i = 2
    // nums[i] = 4
    //
    // Start new = 4
    // Continue  = 6 * 4 = 24
    //
    // Obviously 24 better hai.
    //
    // Lekin agar previous product kharab ho,
    // to sirf current element lena better hoga.*/
            mini = min(nums[i] , mini * nums[i]);
            /*
             // Isi logic se minimum product bhi update karte hain.
    //
    // Ye minimum abhi useless lag sakta hai,
    // lekin future me agar ek aur negative number mila,
    // to yehi minimum maximum ban sakta hai.
    //
    // Example:
    // mini = -12
    // next = -2
    //
    // -12 * -2 = 24
    //
    // Isi wajah se minimum ko bhi store karna zaroori hai.*/
            final = max(final,maxi);
        
    }
        return final;    // Har index ke baad overall answer update karte raho.

    }
    
};