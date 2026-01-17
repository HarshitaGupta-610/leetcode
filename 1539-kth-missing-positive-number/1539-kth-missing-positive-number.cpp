class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        for(int i = 0 ; i < n ; i++){
            if(arr[i] <= k){
                k++;
            }
        }
        return k;

    }
};