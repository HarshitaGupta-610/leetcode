class Solution {
public:
    int hammingWeight(int n) {//counting the number of ones in the binary form
        //Brute force: O(log n)
        // int count = 0;
        // while(n!=0){
        //     int rem = n % 2;
        //     if(rem == 1) count++;
        //     n /= 2;
        // }
        // return count;

        //Better Force: O(log n) check last bit via and and then right shift
//         int count = 0;
//         while(n){
// if(n & 1) count++;
// n >>= 1;
//         }
//         return count;

//optimal : righmost set bit ko remove kro
int count = 0;
while(n){
    n = n & (n-1);//We use n & (n - 1) because subtracting 1 from a number always changes its rightmost 1 bit to 0. When we perform AND with the original number, that rightmost 1 gets removed, while all the other higher bits remain the same.
    count++;
}
return count;
    }
};