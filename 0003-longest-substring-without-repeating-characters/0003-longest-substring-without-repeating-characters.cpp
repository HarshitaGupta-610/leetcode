class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxi  = 0;
        for(int i = 0; i < n; i++){
             int visited[256] = {0};
             for(int j = i ; j < n ; j++){
                if(visited[s[j]] == 1){
                    break;
                }
                visited[s[j]] = 1;
                int curr = j - i +1;
                maxi = max(maxi , curr);
             }
        }
        return maxi;
    }
};