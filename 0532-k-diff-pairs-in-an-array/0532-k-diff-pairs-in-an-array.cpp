class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
         int n = nums.size();
        
        //Brute Force : O(n² log n)
        // set<pair<int,int>>st;
        // for(int i = 0 ; i < n ; i++){
        //     for(int j = i +1 ; j < n ; j++){
        //         if(abs(nums[j] - nums[i])  ==  k){
        //             st.insert({
        //                 min(nums[i] , nums[j]),
        //                 max(nums[i] , nums[j])
        //             });
        //         }
        //     }
        // }
        // return st.size();

//Better:Sort the array and use two pointers to find pairs with difference k → O(n log n)
    // sort(nums.begin() , nums.end());
    //     int i = 0 , j = 1, ans = 0;
    //     while(j < n){
    //         if(i == j) {
    //             j++;
    //               continue;
    //     }
    //         int diff = nums[j] - nums[i];
    //         if(diff == k){
    //             ans++;
    //         int left = nums[i];
    //         int right = nums[j];
    //         while( i < n && nums[i] == left)i++;
    //         while( j < n && nums[j] == right)j++;
    //         }else if(diff<k){
    //             j++;
    //         }else{
    //             i++;
    //         }
    //     }
    //     return ans;



//Optimal:unordered_map me har number ki frequency store karo, phir har unique x ke liye check karo ki x + k exist karta hai ya nahi; k=0 me frequency >=2 honi chahiye → O(n) , x+k and x-k mein se ek hi! Dono valid hain, but same pair opposite direction se 2 baar count ho jayega, isliye unique pairs ke liye ek hi direction (x+k) check karte hain.
        unordered_map<int,int>m;
        for(int num : nums)
        {
          m[num]++;  
        }   
        int ans = 0;
        for(auto &it : m){
            if(k == 0){
                if(it.second >=2){
                    ans++;
                }
            }else{
                if(m.count(it.first+k)){
                    ans++;
                }
            }
        }
        return ans;
    }
};