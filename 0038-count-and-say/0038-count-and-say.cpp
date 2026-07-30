class Solution {
public:
    


//Brute force:O(LENGTH OF FINAL ANSWER)
//if(n==1) return "1";
//         string curr = "1";//intially we have
// for(int step = 2 ; step <= n ;step++){
// string next ="";//append hone wali new string
// for(int i = 0 ; i < curr.size();){
//     int count = 1;
// for(int j = i +1 ; j < curr.size();j++){
// if(curr[i] == curr[j]) count++;
// else break;
// }
// next += to_string(count);
// next+=curr[i];
// i+=count ;
// }
// curr = next;
// }
// return curr;

//Optimal : using recursion:O(total final length)
string rle(const string &s){
    string result ="";
    int count = 1;
    for(int i = 1 ; i < s.size();i++){
        if(s[i] == s[i-1]) count++;
        else{
            result += to_string(count);
            result += s[i-1];
            count = 1;
        }
    }
    result += to_string(count);
        result += s.back();

        return result;
}
string countAndSay(int n) {
     if (n == 1) return "1";
       return rle(countAndSay(n - 1));
}
};