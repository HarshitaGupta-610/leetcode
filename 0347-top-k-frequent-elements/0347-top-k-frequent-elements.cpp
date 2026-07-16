class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       int n = nums.size();
     

// //Brute force: O(N X N) :pehle map mein sabka count daala , fir freq ko priority consider krte huye pairs banke sort kre (pair mein pehla element freq consider kara) uske bad ans vector mein elements yani second value pairs ki dalte gaye aur element set mein daalte gaye aur jaise hi answer vector ka size k hua toh answer mil gaya

// unordered_map<int,int>m;
// for(int i = 0 ; i < n ;i++){
//     int count = 0;
//     for(int j = 0 ; j < n ; j++ ){
//         if(nums[i] == nums[j]){
//             count++;
//         }
//     }
//     m[nums[i]] = count;
// }
// vector<pair<int,int>> freq;
// for(auto it : m){
// freq.push_back({it.second , it.first});
// }
// sort(freq.begin() , freq.end() , greater<pair<int,int>>());
// vector<int>ans;
// unordered_set<int>s;
// for(auto it : freq){
//     if(s.find(it.second) == s.end()){
//         ans.push_back(it.second);
//         s.insert(it.second);
//     }
//      if(ans.size() ==k){
//         return ans;
//     }
// } 
// return{};
//     }



// //optimal approach : O(n logn) : pehle short krege aur ek hi traversal mein freq increase krte rhege aur pairs mein freq aur number store krege , then pairs ko freq waise sort krke , elements jab tak vector ka size k na hojaye tab tak push krte rehege
// sort(nums.begin() , nums.end());
// vector<pair<int,int>>freq;
// int count = 1;
// for(int i = 0 ; i < n; i++){
//     while( i + 1 < n && nums[i] == nums[i+1]){
//         count++;
//         i++;
//     }
//     freq.push_back({count , nums[i]});
//     count = 1;

// }
// sort(freq.begin() , freq.end() , greater<pair<int,int>>());
// vector<int>ans;
// for(int i = 0 ; i < k ; i++){
//     ans.push_back(freq[i].second);
// }
// return ans;
//     }



//optimal :O(n + m log k + k log k) or o(nlog k):pehle map banake freq count badhao and then min heap banao jsime freq ke basis pe minimum top pe hoga aur jaise hi size k hoga toh minimum freq wala bahr aajayega 
// Min Heap use karte hain kyuki hume minimum frequency ko baar-baar remove karna hai. Heap mein hamesha current Top K frequencies rehti hain, aur jaise hi size k se bada hota hai, minimum frequency bahar nikal jaati hai.

unordered_map<int,int>m;
for(int num : nums){
    m[num]++;
}
priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>pq;
for(auto it : m){
    pq.push({it.second , it.first});
    if(pq.size() > k){
        pq.pop();
    }
}
vector<int>ans;
while(!pq.empty()){
    ans.push_back(pq.top().second);
    pq.pop();
}
return ans;
    }
};