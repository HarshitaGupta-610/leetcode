class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int>pos;
        int n = seats.size();
             for(int i = 0 ; i < n ; i++){
if(seats[i] == 1){
    pos.push_back(i);
}
             }
             int ans = 0;
             ans = pos[0];
             for(int i = 1 ; i < pos.size() ; i++){
                int gap = pos[i] - pos[i-1];
                ans = max(ans , gap/2);
             }
             ans = max(ans , n-1-pos.back());
             return ans;

    }
};