class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();


    //     //brute force : O(N XN) : har element ko chorke uske aalwa sabka
    //product lele , nested loop chalao
    //     vector<int>ans;
    //     for(int i = 0 ; i < n ; i++){
    //         int prod = 1;
    //         for(int j = 0 ; j < n; j++){
    //             if(j == i){
    //                 continue;
    //             }
    //      prod *= nums[j];
    //         }
    //         ans.push_back(prod);
    //     }
    //     return ans;
    // }


    //Optimal Approach : O(n) using prodcut of element except that is 
    /*
    mul[i] = suffix[i] * prefix[i] 
    uske bad ke sare elements aur usse pehle sare elements ka product
    */ 
    vector<int>ans(n,1);
    vector<int>prefix(n,1);    
    vector<int>suffix(n,1); 
    for(int i = 1 ; i < n ; i++){
        prefix[i] *= prefix[i-1] * nums[i-1];
        

    }
    for(int i = n-2 ; i >= 0 ; i--){
        suffix[i] = suffix[i+1]*nums[i+1];
        
    }
    for(int i = 0 ; i < n ;i++){
        ans[i] = prefix[i] * suffix[i];
    }
    return ans;
    }

};