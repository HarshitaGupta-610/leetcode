class Solution {
public:
    int hammingWeight(int n) {//counting the number of ones in the binary form
        //Brute force: O(log n)
        int count = 0;
        while(n!=0){
            int rem = n % 2;
            if(rem == 1) count++;
            n /= 2;
        }
        return count;
    }
};