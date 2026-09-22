class Solution {
public:
    void nextPermutation(vector<int>& a) {
         int n = a.size();
    int i = n-2;//to find character form end 
    while( i >= 0 && a[i] >= a[i+1]){
        i--;
    }
if(i >= 0){
    int j = n-1;// finding right side pe sabse smallest to exchange with ith
    while(a[j] <= a[i]) j--;
    swap(a[j] , a[i]);

}
reverse(a.begin() + i + 1, a.end());
    }
};