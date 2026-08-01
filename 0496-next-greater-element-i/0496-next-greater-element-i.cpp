class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();


        //Brute Force: O(N1XN2) : search via nested loops
//         vector<int>indexes;
// for(int i = 0 ; i < n1 ; i++){
// for(int j = 0 ; j < n2 ; j++){
// if(nums1[i] == nums2[j]) indexes.push_back(j);
// }
// }
// vector<int>ans;
// for(int i = 0 ; i < indexes.size() ; i++){
//     bool possible = false;
// for(int j = indexes[i]+1 ; j < n2 ; j++){
// if(nums2[j] > nums2[indexes[i]]){
//     ans.push_back(nums2[j]);
//     possible = true;
//     break;
// }
// }
// if(possible == false) ans.push_back(-1);
// }
// return ans;


//Optimal Approach : Ek baar nums2 ke sab next greater elements stack se calculate kar lo, phir nums1 ke liye sirf map se answer le lo.
stack<int>st;
unordered_map<int,int>m;
for(int i = n2-1; i >= 0 ; i--){
    while(!st.empty() && st.top()<= nums2[i]){
        st.pop();
    }
    if(st.empty()) m[nums2[i]] = -1;
    else m[nums2[i]] = st.top();
    st.push(nums2[i]);
}
vector<int>ans;
for(int i = 0 ; i < n1 ; i++){
    ans.push_back(m[nums1[i]]);
}
return ans;
 }
};