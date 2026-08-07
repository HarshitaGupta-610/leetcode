class Solution {
public:
    int getSum(int a, int b) {
        //sum using xor operator
        //carry using and operator 
        //followed by a left shift
        /*
        sum = a ^ b;
carry = (a & b) << 1;
*/
//Initially: a = Number 1 b = Number 2 
// After first iteration:
// a = Sum
// b = Carry

// After that:
// b is ALWAYS the carry.
while(b!= 0){
    int sum  = a ^ b;
    int carry = a & b ;
    carry <<= 1;
    a = sum ;
    b = carry;
}
return a;
    }
};