class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        long long ans =1;
        long long MOD = 1000000007;
        int n=complexity.size();
        for (int i=1;i<n;i++){
            if (complexity[i]<=complexity[0]){
                return 0;
            }
           ans=(ans*i)%MOD;

        }

        return (int) ans;

    }
};