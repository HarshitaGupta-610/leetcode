class Solution {
public:
    string smallestGoodBase(string n) {
        //Base k : 0 to k-1 tak ke digits se number ko represent krna
        //best smalles base jiss number ko represent krein tohs are digits 1 hon
        //a base cannot be greater than or equal to the number as remanider would be always that number then

   long long num = stoll(n);
// //Brute : O(n-1)
// bool cond = true;//han present k se rem 1 hi reh raha hai ya nahi
// for(long long k = 2 ; k < num ; k++){
// long long save = num;
// while(save!=0){
//     if(save % k != 1){
//         cond = false;
//         break;
//     }else{
//         save /=k;
//         cond = true;
//     }
// }
// if(cond == true) 
// return to_string(k);
// }
// return "";
//     }


//optimal :
//Jitna base chhota hota gaya, utni zyada ones aati gayi.
//Sabse zyada ones kab aayengi ;Sabse chhota allowed base hai

// 1. If n = 111...111 (m total ones) in base k:
//    n = 1 + k + k² + ... + k^(m-1)
// 2. Smaller base ⇒ More divisions ⇒ More digits ⇒ More ones
// 3. Maximum ones always occur in Base = 2
// 4. In base 2:
//    1      = 2¹ - 1
//    11     = 2² - 1
//    111    = 2³ - 1
//    1111   = 2⁴ - 1
//    ...
//    m ones = 2^m - 1
// 5. Since n ≤ 10¹⁸:
//    2^m - 1 ≤ 10¹⁸
//    ⇒ m ≤ log₂(10¹⁸ + 1) ≈ 60
//  Therefore, we only need to try m = 60 down to 2.
//For a fixed m, only k is unknown and
// sum = 1 + k + k² + ... + k^(m-1) increases as k increases.
// Since the sum is monotonic (strictly increasing), Binary Search can efficiently find the correct k.
//Humein minimum base chahiye, isliye maximum possible m (ones) se start karte hain.
 for (int m = 60; m >= 2; m--) {

            long long l = 2;
            long long r = pow(num, 1.0 / (m - 1));

            while (l <= r) {

                long long k = l + (r - l) / 2;

                __int128 sum = 1;
                __int128 term = 1;

                for (int i = 1; i < m; i++) {
                    term *= k;
                    sum += term;

                    if (sum > num)break;
                }

                if (sum == num) return to_string(k);

                if (sum < num) l = k + 1;
                else r = k - 1;
            }
        }
        return to_string(num - 1);
    }
};