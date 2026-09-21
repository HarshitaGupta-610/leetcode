class Solution {
public:
 vector<vector<int>>fourSum(vector<int>&a, int target ){
vector<vector<int>>ans;
sort(a.begin()  , a .end());
int n = a.size();
for(int i = 0 ; i <= n-4 ; i++){
if(i > 0 && a[i] == a[i-1]) continue;
for(int j = i+1 ; j <= n-3 ; j++){
    if(j > i + 1 && a[j] == a[j-1]) continue;
    int l = j +1 ;
    int r = n-1;

    while( l < r){
        long long sum = (long long)a[i] + a[j] + a[l] + a[r];
        if(sum == target) {
            ans.push_back({a[i] , a[j] , a[l] , a[r]});

       while( l < r && a[l] == a[l+1])l++;
       while( l < r && a[r] == a[r-1])r--;
l++;
r--;
        }
        else if(sum < target) l++;
        else r--;

    }
}

}
return ans;

}
};