class Solution {
public:
    long long countCommas(long long n) {
      if(n<1000) return 0;
  /*
  Numbers from 1000 onward have at least 1 comma.
Numbers from 1000000 onward have an additional 2nd comma.
Numbers from 1000000000 onward have an additional 3rd comma.
*/
//p represents the number from which a particular comma starts appearing, so we first set p = 1000
//ans stores the total number of commas
//n - p + 1 calculates how many numbers from p to n contain that comma   
//then p *= 1000 moves p to the next comma position
long long ans = 0;
long long p = 1000;
while(n>=p){
    ans += n-p+1;
    p*=1000;
}
return ans;

    }
};