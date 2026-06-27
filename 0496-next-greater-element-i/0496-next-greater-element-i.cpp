class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int , int>mpi;
        stack<int>sti;
        int n2 = nums2.size();
        for(int i = n2 - 1; i >= 0 ; i--){
            while(!sti.empty() && sti.top()<= nums2[i]){
                sti.pop();
            }
            if(sti.empty()){
            mpi[nums2[i]]= -1;
            }
            else{
                mpi[nums2[i]] = sti.top();
            }
            sti.push(nums2[i]);
        }
        int n1 = nums1.size();
        vector<int>ans(n1);
        for(int i = 0 ; i < n1 ; i++){
            ans[i] = mpi[nums1[i]];
        }
        return ans;
    }
};