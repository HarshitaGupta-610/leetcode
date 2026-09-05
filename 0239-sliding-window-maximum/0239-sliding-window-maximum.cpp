class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
int n = nums.size();
vector<int>ans;

//Brute : O(n *k)

// for(int i = 0 ; i <= n-k; i++){
//     int maxi = nums[i];
//     for(int j = i ; j < i+k ; j++){
//         maxi = max(maxi,nums[j]);
//     }
//     ans.push_back(maxi);
// }
// return ans;

//Optimal : O(N) via dequeue
/*
 DEQUE ka use isliye:
            1. Front se element remove kar sakte hain
               -> jab koi index window se bahar chala jaye
            2. Back se element remove kar sakte hain
               -> jab current element unse bada ho
                  kyunki chhote elements future mein maximum
                  nahi ban sakte*/
deque<int>dq;//donon end se remove ya add , store indices We store indices instead of values because we need to know when an element goes out of the sliding window; the value can always be obtained using nums[index].
for ( int i = 0 ; i < n ; i++ ) {
// remove elements outside the window
 while ( !dq.empty() && dq.front() <= i-k ) dq.pop_front() ;
            // remove smaller elements
 while ( !dq.empty() && nums[i] >= nums[dq.back()] ) dq.pop_back() ;
dq.push_back(i) ;
            // now window is ready , front of deqeue is our answer
            if ( i >= k-1 ) ans.push_back(nums[dq.front()]) ;
        }
return ans;
    }
};