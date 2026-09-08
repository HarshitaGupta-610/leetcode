class Solution {
public:
    int countCommas(int n) {
        if( n <= 999){
            return 0;
        }
        int ans = n - 999;//s digit se kitne digit zyada hai kyuki thousands tak hi jayega maximum
        return ans;
    }
};