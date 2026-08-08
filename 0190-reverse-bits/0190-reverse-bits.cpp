class Solution {
public:

/*
//Brute force:O(1)
    // Decimal ko 32-bit binary string me convert karo
    string toBinary(uint32_t n) {
        string binary = "";
        // Binary digits nikalo
        while (n > 0) {
            binary += (n % 2) + '0';
            n /= 2;
        }
        // Binary ko sahi order me lao
        reverse(binary.begin(), binary.end());
        // Leading 0's add karo taaki 32 bits ho jaye
        while (binary.size() < 32) {
            binary = '0' + binary;
        }
        return binary;
    }
    // Binary string ko decimal me convert karo
    uint32_t toDecimal(string binary) {
        uint32_t num = 0;
        for (char bit : binary) {
            num = num * 2 + (bit - '0');
        }
        return num;
    }
    uint32_t reverseBits(uint32_t n) {
        // Step 1: Decimal -> Binary
        string binary = toBinary(n);
        // Step 2: Binary reverse karo
        reverse(binary.begin(), binary.end());
        // Step 3: Binary -> Decimal
        return toDecimal(binary);
    }
    */

  //optimal:Har baar LSB (n & 1) nikalo, answer ko left shift karke jagah banao, bit insert karo (|), aur n ko right shift (>>) karke next bit pe jao
    uint32_t reverseBits(uint32_t n) {
        // Final answer jisme reversed bits store hongi
        uint32_t ans = 0;
        // 32-bit integer hai, isliye exactly 32 bits process karni hain
        for(int i = 0; i < 32; i++) {
            // Current number ki last bit (LSB) nikalo
            // Agar last bit 1 hai to bit = 1
            // Agar last bit 0 hai to bit = 0
            int bit = n & 1;
            // Answer ko ek position left shift karo
            // Taaki right side me ek nayi jagah ban jaye
            ans = ans << 1;
            // Jo bit humne nikali hai use answer me insert kar do
            // Agar bit = 1 hai to last position 1 ho jayegi
            // Agar bit = 0 hai to answer same rahega
            ans = ans | bit;
       // Current number ko right shift karo
            // Taaki next iteration me next bit last bit ban jaye
            n = n >> 1;
        }

     // Reversed bits wala answer return karo
        return ans;
    }
};