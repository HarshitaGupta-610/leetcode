class Solution {
public:
    vector<int> countBits(int n) {
     
      //Brute force: O( n logn): Har number ke liye check karo
//       vector<int>ans;
//     for(int num = 0 ; num <= n ; num++){//i ki value us number tak jayegi jo given hai
//     int count = 0;
//     int i = num;
//    while(i != 0){
//     int rem = i % 2;
//     if(rem == 1) count++;
//     i /= 2;
//    }
//    ans.push_back(count); 

//     }  
//     return ans;


//Better Approach :O(n log n) using concept of last set bit and then right shifting by one
      vector<int>ans;
    for(int num = 0 ; num <= n ; num++){//i ki value us number tak jayegi jo given hai
    int count = 0;
    int i = num;
   while(i != 0){
    if(i & 1) count++;
    i >>= 1;
   }
   ans.push_back(count); 

    }  
    return ans;
    }
};