class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();


        //Brute Force: O(NXN) : search via nested loops
        vector<int>indexes;
for(int i = 0 ; i < n1 ; i++){
for(int j = 0 ; j < n2 ; j++){
if(nums1[i] == nums2[j]) indexes.push_back(j);
}
}
vector<int>ans;
for(int i = 0 ; i < indexes.size() ; i++){
    bool possible = false;
for(int j = indexes[i]+1 ; j < n2 ; j++){
if(nums2[j] > nums2[indexes[i]]){
    ans.push_back(nums2[j]);
    possible = true;
    break;
}
}
if(possible == false) ans.push_back(-1);
}
return ans;
    }
};